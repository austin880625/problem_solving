import curses
curses.initscr()
curses.start_color()
curses.init_pair(1,curses.COLOR_RED,curses.COLOR_GREEN)
class block:
    def __init__(self, posx, posy, bType):
        self.posx=posx
        self.posy=posy
        self.bType=bType

    def draw(self,scr):
        scr.addstr(self.posx,self.posy,' ',curses.color_pair(1))
