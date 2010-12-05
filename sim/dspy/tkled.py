#/*
#Python and Tkinter Programming
#John E. Grayson

#ISBN: 1884777813
#Publisher: Manning
#*/
from tkinter   import *

SQUARE      = 1
ROUND       = 2
ARROW       = 3

POINT_DOWN  = 0
POINT_UP    = 1
POINT_RIGHT = 2
POINT_LEFT  = 3

STATUS_OFF   = 1
STATUS_ON    = 2
STATUS_WARN  = 3
STATUS_ALARM = 4
STATUS_SET   = 5

class DummyClass:
    pass

Color  = DummyClass()

Color.PANEL     = '#545454'
Color.OFF       = '#656565'
Color.ON        = '#00FF33'
Color.WARN      = '#ffcc00'
Color.ALARM     = '#ff4422'

class LED:
    def __init__(self, master=None, width=25, height=25,
                 appearance=FLAT,
                 status=STATUS_ON, bd=1,
                 bg=None,
                 shape=SQUARE, outline="",
                 blink=0, blinkrate=1,
                 orient=POINT_UP,
                 takefocus=0):
        # preserve attributes
        self.master       = master
        self.shape        = shape
        self.onColor      = Color.ON
        self.offColor     = Color.OFF
        self.alarmColor   = Color.ALARM
        self.warningColor = Color.WARN
        self.specialColor = '#00ffdd'
        self.status       = status
        self.blink        = blink
        self.blinkrate    = int(blinkrate)
        self.on           = 0
        self.onState      = None

        if not bg:
            bg = Color.PANEL

        ## Base frame to contain light
        self.frame=Frame(master, relief=appearance, bg=bg, bd=bd,
                         takefocus=takefocus)

        basesize = width
        d = center = int(basesize/2)

        if self.shape == SQUARE:
            self.canvas=Canvas(self.frame, height=height, width=width,
                               bg=bg, bd=0, highlightthickness=0)

            self.light=self.canvas.create_rectangle(0, 0, width, height,
                                                    fill=Color.ON)
        elif self.shape == ROUND:
            r = int((basesize-2)/2)
            self.canvas=Canvas(self.frame, width=width, height=width,
                               highlightthickness=0, bg=bg, bd=0)
            if bd > 0:
                self.border=self.canvas.create_oval(center-r, center-r,
                                                    center+r, center+r)
                r = r - bd
            self.light=self.canvas.create_oval(center-r-1, center-r-1,
                               center+r, center+r, fill=Color.ON,
                               outline=outline)
        else:  # Default is an ARROW
            self.canvas=Canvas(self.frame, width=width, height=width,
                               highlightthickness=0, bg=bg, bd=0)
            x = d
            y = d
            if orient == POINT_DOWN:
                self.light=self.canvas.create_polygon(x-d,y-d, x,y+d,
                               x+d,y-d, x-d,y-d, outline=outline)
            elif orient == POINT_UP:
                self.light=self.canvas.create_polygon(x,y-d, x-d,y+d,
                               x+d,y+d, x,y-d, outline=outline)
            elif orient == POINT_RIGHT:
                self.light=self.canvas.create_polygon(x-d,y-d, x+d,y,
                               x-d,y+d, x-d,y-d, outline=outline)
            elif orient == POINT_LEFT:
                self.light=self.canvas.create_polygon(x-d,y, x+d,y+d,
                               x+d,y-d, x-d,y, outline=outline)

        self.canvas.pack(side=TOP, fill=X, expand=NO)
        self.update()

    def turnon(self):
        self.status = STATUS_ON
        if not self.blink: self.update()

    def turnoff(self):
        self.status = STATUS_OFF
        if not self.blink: self.update()

    def alarm(self):
        self.status = STATUS_ALARM
        if not self.blink: self.update()

    def warn(self):
        self.status = STATUS_WARN
        if not self.blink: self.update()

    def set(self, color):
        self.status       = STATUS_SET
        self.specialColor = color
        self.update()

    def blinkon(self):
        if not self.blink:
            self.blink   = 1
            self.onState = self.status
            self.update()

    def blinkoff(self):
        if self.blink:
            self.blink   = 0
            self.status  = self.onState
            self.onState = None
            self.on      = 0
            self.update()

    def blinkstate(self, blinkstate):
        if blinkstate:
            self.blinkon()
        else:
            self.blinkoff()

    def update(self):
        # First do the blink, if set to blink
        if self.blink:
            if self.on:
                if not self.onState:
                    self.onState = self.status
                self.status  = STATUS_OFF
                self.on      = 0                            
            else:
                if self.onState:
                    self.status = self.onState     # Current ON color
                self.on = 1

        if self.status == STATUS_ON:
            self.canvas.itemconfig(self.light, fill=self.onColor)
        elif self.status == STATUS_OFF:
            self.canvas.itemconfig(self.light, fill=self.offColor)
        elif self.status == STATUS_WARN:
            self.canvas.itemconfig(self.light, fill=self.warningColor)
        elif self.status == STATUS_SET:
            self.canvas.itemconfig(self.light, fill=self.specialColor)
        else:
            self.canvas.itemconfig(self.light, fill=self.alarmColor)

        self.canvas.update_idletasks()

        if self.blink:
            self.frame.after(self.blinkrate * 1000, self.update)

if __name__ == '__main__':
    class TestLEDs(Frame):
        def __init__(self, parent=None):

            # List of Colors and Blink On/Off
            states = [(STATUS_OFF,   0),
                      (STATUS_ON,    0),
                      (STATUS_WARN,  0),
                      (STATUS_ALARM, 0),
                      (STATUS_SET,   0),
                      (STATUS_ON,    1),
                      (STATUS_WARN,  1),
                      (STATUS_ALARM, 1),
                      (STATUS_SET,   1)]

            # List of LED types to display,
            # with sizes and other attributes
            leds = [(ROUND,  25, 25, FLAT,   0, None,        ""),
                    (ROUND,  15, 15, RAISED, 1, None,        ""),
                    (SQUARE, 20, 20, SUNKEN, 1, None,        ""),
                    (SQUARE,  8,  8, FLAT,   0, None,        ""),
                    (SQUARE,  8,  8, RAISED, 1, None,        ""),
                    (SQUARE, 16,  8, FLAT,   1, None,        ""),
                    (ARROW,  14, 14, RIDGE,  1, POINT_UP,    ""),
                    (ARROW,  14, 14, RIDGE,  0, POINT_RIGHT, ""),
                    (ARROW,  14, 14, FLAT,   0, POINT_DOWN,  "white")]

            Frame.__init__(self)              # Do superclass init
            self.pack()
            self.master.title('LED Example - Stage 1')

            # Iterate for each type of led
            for shape, w, h, app, bd, orient, outline in leds:
                frame = Frame(self, bg=Color.PANEL)
                frame.pack(anchor=N, expand=YES, fill=X)

                # Iterate for selected states
                for state, blink in states:
                    LED(frame, shape=shape, status=state,
                        width=w, height=h, appearance=app,
                        orient=orient, blink=blink, bd=bd,
                        outline=outline).frame.pack(side=LEFT,
                                      expand=YES, padx=1, pady=1)

    TestLEDs().mainloop()

