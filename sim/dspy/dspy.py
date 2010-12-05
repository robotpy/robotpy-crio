# Copyright (C) 2010 Peter Johnson
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#  - Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  - Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND OTHER CONTRIBUTORS ``AS IS''
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR OTHER CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

"""Python FRC Driver Station Demo Application."""

from tkinter import *
from tkinter.ttk import *
from tkinter import font
import tkled
import threading

import sys
if ".." not in sys.path:
    sys.path.insert(0, "..")
from netcomm.dscomm import DriverStationComm

DEFAULT_TEAM_ID = "294"

class Application(Frame):
    def data_update(self):
        self.data_update_count += 1

        if self.ds.have_data.is_set():
            self.data_update_count = 0
            with self.ds.mutex:
                have_code = self.ds.state.status.is_code_running()
                battery = self.ds.state.status.battery
                enabled = self.ds.state.status.control.enabled
                autonomous = self.ds.state.status.control.autonomous
                self.ds.have_data.clear()

            self.have_comm.turnon()
            if have_code:
                self.have_code.turnon()
                if autonomous:
                    self.bigstate1.set("Autonomous")
                else:
                    self.bigstate1.set("Teleoperated")
                if enabled:
                    self.bigstate2.set("Enabled")
                else:
                    self.bigstate2.set("Disabled")
            else:
                self.have_code.alarm()
                self.bigstate1.set("No Robot")
                self.bigstate2.set("Code")
            self.volts.set("%1.2f" % battery)
        elif self.data_update_count > 5:
            self.have_comm.alarm()
            self.have_code.alarm()
            self.volts.set("--.--")
            self.bigstate1.set("No Robot")
            self.bigstate2.set("Communication")

        self.after(20, self.data_update)

    def create_variables(self):
        self.team_id = StringVar()
        self.team_id.set(DEFAULT_TEAM_ID)

        self.volts = StringVar()
        self.volts.set("--.--")

        self.bigstate1 = StringVar()
        self.bigstate1.set("No Robot")
        self.bigstate2 = StringVar()
        self.bigstate2.set("Communication")

        self.runstate = StringVar()
        self.runstate.set("teleop")

        self.is_local = IntVar()
        self.is_local.set(0)

    def enable_robot(self, *args):
        if (self.have_comm.status != tkled.STATUS_ON or
            self.have_code.status != tkled.STATUS_ON):
            return
        with self.ds.mutex:
            self.ds.state.control.control.enabled = True
        print("Robot enabled!")

    def disable_robot(self, *args):
        if (self.have_comm.status != tkled.STATUS_ON or
            self.have_code.status != tkled.STATUS_ON):
            return
        with self.ds.mutex:
            self.ds.state.control.control.enabled = False
        print("Robot disabled.")

    def update_runstate(self, *args):
        runstate = self.runstate.get()
        with self.ds.mutex:
            self.ds.state.control.control.autonomous = (runstate == "auto")

    def validate_team_id(self, to_insert):
        if not '0' <= to_insert <= '9':
            return False
        return True

    def set_team_id(self, *args):
        team_id = int(self.team_id.get())
        print("New team number: %d." % team_id)
        self.ds.stop()
        if self.is_local.get() == 0:
            self.ds = DriverStationComm(team_id)
        else:
            self.ds = DriverStationComm(team_id, robot_addr="127.0.0.1",
                                        ds_addr="127.0.0.1")

    def create_widgets(self):
        oper_frame = Frame(self, padding=(3,3,12,12))
        oper_frame.grid(column=0, row=0, sticky=(N, S, E, W))

        volts_frame = Frame(oper_frame, borderwidth=5)
        volts_frame.grid(column=0, row=0, sticky=(N, W, E, S))
        state_frame = Frame(oper_frame, borderwidth=5)
        state_frame.grid(column=0, row=1, sticky=(N, W, E, S))
        bigstate_frame = Frame(oper_frame, borderwidth=5)
        bigstate_frame.grid(column=0, row=2, sticky=(S, W, E, N))
        status_frame = Frame(oper_frame, borderwidth=5)
        status_frame.grid(column=1, row=0, rowspan=3, sticky=(N, S, E, W))

        enable_frame = Frame(status_frame, borderwidth=5)
        enable_frame.grid(column=0, row=0)
        timestation_frame = Frame(status_frame, borderwidth=5)
        timestation_frame.grid(column=1, row=0)
        usermessages_frame = Frame(status_frame, borderwidth=5)
        usermessages_frame.grid(column=2, row=0)

        status_frame.columnconfigure(0, weight=1)
        status_frame.columnconfigure(1, weight=2)
        status_frame.columnconfigure(2, weight=4)

        volts_font = font.Font(family="Arial", size=16)
        volts_label = Label(volts_frame, text="Volts", font=volts_font)
        volts_label.grid(column=0, row=0)
        volts_display = Label(volts_frame, textvariable=self.volts,
                              font=volts_font)
        volts_display.grid(column=1, row=0)

        self.have_comm = tkled.LED(state_frame, shape=tkled.SQUARE,
                                   status=tkled.STATUS_ALARM, width=8, height=8)
        self.have_comm.frame.grid(column=0, row=0)
        comm_label = Label(state_frame, text="Communications")
        comm_label.grid(column=1, row=0, sticky=W)

        self.have_code = tkled.LED(state_frame, shape=tkled.SQUARE,
                                   status=tkled.STATUS_ALARM, width=8, height=8)
        self.have_code.frame.grid(column=0, row=1)
        robotcode_label = Label(state_frame, text="Robot Code")
        robotcode_label.grid(column=1, row=1, sticky=W)

        bigstate_font = font.Font(family="Arial", size=14, weight="bold")
        bigstate_label1 = Label(bigstate_frame, textvariable=self.bigstate1,
                               font=bigstate_font, justify="center")
        bigstate_label1.grid(column=0, row=0, sticky=(E,W))
        bigstate_label2 = Label(bigstate_frame, textvariable=self.bigstate2,
                               font=bigstate_font, justify="center")
        bigstate_label2.grid(column=0, row=1, sticky=(E,W))

        bigstate_frame.columnconfigure(0, minsize=200, weight=0)

        team_label = Label(enable_frame, text="Team #")
        team_label.grid(column=0, row=0, sticky=W)
        team_entry_validate = (self.register(self.validate_team_id), '%S')
        team_entry = Entry(enable_frame, width=4, textvariable=self.team_id,
                           takefocus=False, validate="key",
                           validatecommand=team_entry_validate)
        team_entry.grid(column=1, row=0, sticky=W)
        set_team_button = Button(enable_frame, text="Set", width=4,
                                 takefocus=False, command=self.set_team_id)
        set_team_button.grid(column=2, row=0, sticky=W)
        local_sim = Checkbutton(enable_frame, text="Local (simulate)",
                                variable=self.is_local, takefocus=False,
                                command=self.set_team_id)
        local_sim.grid(column=0, row=1, columnspan=2, sticky=W)

        teleop_radio = Radiobutton(enable_frame, text="Teleoperated",
                                   variable=self.runstate, value="teleop",
                                   command=self.update_runstate,
                                   takefocus=False)
        teleop_radio.grid(column=0, row=2, columnspan=2, sticky=W)
        auto_radio = Radiobutton(enable_frame, text="Autonomous",
                                 variable=self.runstate, value="auto",
                                 command=self.update_runstate,
                                 takefocus=False)
        auto_radio.grid(column=0, row=3, columnspan=2, sticky=W)
        #practice_radio = Radiobutton(enable_frame, text="Practice",
        #                             variable=self.runstate,
        #                             value="practice")
        #practice_radio.grid(column=0, row=4, columnspan=2, sticky=W)
        enable_button = Button(enable_frame, text="Enable",
                               command=self.enable_robot, takefocus=False)
        enable_button.grid(column=0, row=5, columnspan=2, sticky=(E,W))
        disable_button = Button(enable_frame, text="Disable",
                                command=self.disable_robot,
                                takefocus=False)
        disable_button.grid(column=0, row=6, columnspan=2, sticky=(E,W))

    def __init__(self, master=None):
        super().__init__(master)
        self.grid(column=0, row=0, sticky=(N, S, E, W))
        self.create_variables()
        self.ds = DriverStationComm(int(self.team_id.get()))
        self.create_widgets()
        for child in self.winfo_children():
            child.grid_configure(padx=5, pady=5)

        self.data_update_count = 0
        self.after(20, self.data_update)

        self.bind_all("<space>", self.disable_robot)

root = Tk()
root.title("FRC Python Driver Station")
app = Application(master=root)
app.mainloop()

