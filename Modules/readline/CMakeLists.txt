
add_definitions(-DHAVE_CONFIG_H)
include_directories(readline)

get_filename_component(MODULE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)
add_executable(${MODULE_NAME}.pyd readline/bind.c
                                  readline/callback.c
                                  readline/compat.c
                                  readline/complete.c
                                  readline/display.c
                                  readline/funmap.c
                                  readline/histexpand.c
                                  readline/histfile.c
                                  readline/history.c
                                  readline/histsearch.c
                                  readline/input.c
                                  readline/isearch.c
                                  readline/keymaps.c
                                  readline/kill.c
                                  readline/macro.c
                                  readline/mbutil.c
                                  readline/misc.c
                                  readline/nls.c
                                  readline/parens.c
                                  readline/readline.c
                                  readline/rltty.c
                                  readline/savestring.c
                                  readline/search.c
                                  readline/shell.c
                                  readline/signals.c
                                  readline/terminal.c
                                  readline/text.c
                                  readline/tilde.c
                                  readline/undo.c
                                  readline/util.c
                                  readline/vi_mode.c
                                  readline/xmalloc.c
                                  termcap/termcap.c
                                  termcap/tgoto.c
                                  termcap/tputs.c
                                  readline.c)

install(TARGETS ${MODULE_NAME}.pyd DESTINATION robot/lib/python3.2/lib-dynload)