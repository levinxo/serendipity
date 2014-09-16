# -*- coding: utf-8 -*-

import wx


class Frame(wx.Frame):
    def __init__(self, **kwargs):
        title = kwargs['title'] if 'title' in kwargs else 'default title'
        parent = kwargs['parent'] if 'parent' in kwargs else None
        wx.Frame.__init__(self, parent, wx.ID_ANY, title)


class App(wx.App):
    def __init__(self, redirect=False):
        wx.App.__init__(self, redirect)

    def OnInit(self):
        self.font = wx.Font(12, wx.MODERN, wx.NORMAL, wx.NORMAL, False, u'Consolas')
        self.main()
        return True

    def main(self):
        self.frame = Frame()
        self.frame.Bind(wx.EVT_CLOSE, self.__exit, self.frame)
        self.frame.CreateStatusBar()

        help_menu = wx.Menu()
        on_help_menu_about = help_menu.Append(wx.ID_ABOUT, u'关于', u'关于此程序')
        menu_bar = wx.MenuBar()
        menu_bar.Append(help_menu, u'帮助')
        self.frame.SetMenuBar(menu_bar)

        self.frame.Bind(wx.EVT_MENU, self.on_help_menu_about, on_help_menu_about)

        self.frame.button = wx.Button(self.frame, -1, "Click me", pos=(150,150))
        self.frame.Bind(wx.EVT_BUTTON, self.on_btn_click, self.frame.button)
        self.frame.button.SetDefault()

        self.frame_sizer = wx.BoxSizer(wx.HORIZONTAL)
        self.frame.SetSizer(self.frame_sizer)
        self.frame_sizer.Fit(self.frame)
        self.frame.SetSize((900, 500))
        self.frame.Show()

    def on_btn_click(self, event):
        self.frame.button.SetLabel('Hello')

    def on_help_menu_about(self, event):
        dlg = wx.MessageDialog(self.frame, u"A Simple wxPython Demo\r\n\r\n(c) Levin", u'关于', wx.OK)
        dlg.ShowModal()
        dlg.Destroy()

    def __exit(self, event):
        self.Exit()


app = App()
app.MainLoop()
