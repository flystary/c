
class Printer:

  def __init__(self, color):
    self.color = color

  def do_print(self, news):
    print('print %s in %s' % (news, self.color))



class User:

  def __init__(self, news, printer_color):
    self.printer = Printer(printer_color)
    self.news = news

  def print_newspaper(self):
    self.printer.do_print(self.news)


# user = User('hello world', 'red')


'''
class User:

    def __init__(self, news, printer):
        self.printer = printer
        self.news = news

    def print_newspaper(self):
        self.printer.do_print(self.news)

printer = Printer('red')
user = User('hello world', printer)

'''

'''
# 属性注入
printer = Printer('blue')

# 接口注入
class User:

  def __init__(self, news):
    self.news = news
    self.printer = None

  def print_newspaper(self, printer):
    printer.do_print(self.news)

  def set_printer(self, printer):
    self.printer = printer

user = User('hello world')
printer = Printer('blue')
user.set_printer(printer)


'''

class DebugPrinter:
    def __init__(self, color):
        self.color = color

    def do_print(self, news):
        print("debug start ...")
        print('print %s in %s' % (news, self.color))
        print('debug end ...')

debug_printer = DebugPrinter('red')
user = User('hello world', debug_printer)
