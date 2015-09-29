import curses
import tetris
scr = curses.initscr()
curses.cbreak()
scr.keypad(1)

while scr.getch()!=ord('q'):
    curses.start_color()
    block=tetris.block(20,30,1)
    block.draw(scr)
    
    scr.refresh()

scr.keypad(0)
curses.echo()
curses.endwin()
