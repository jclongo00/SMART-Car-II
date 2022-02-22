# button_events.py
import wx

class MyPanel(wx.Panel):
    
    def __init__(self, parent):
        super().__init__(parent)
        
        textBox = wx.TextCtrl(self, value = "",style = wx.TE_READONLY|wx.TE_MULTILINE, pos =(250, 300), size =(1400, 300))
        
        button1 = wx.Button(self, label='Point-to-Point Navigation', pos =(800, 60), size =(300, 40))
        button1.Bind(wx.EVT_BUTTON, self.on_button1)
        
        button2 = wx.Button(self, label='Adaptive Cruise Control', pos =(800, 120), size =(300, 40))
        button2.Bind(wx.EVT_BUTTON, self.on_button2)
        
        button3 = wx.Button(self, label='Auto Parking', pos =(800, 180), size =(300, 40))
        button3.Bind(wx.EVT_BUTTON, self.on_button3)
        
        exitButton = wx.Button(self, label='Exit', pos =(875, 800), size =(150, 40))
        exitButton.Bind(wx.EVT_BUTTON, self.on_exitButton)
        
        #textBox.SetValue('Starting Point-to-Point Navigation Module...')
        #textBox.SetValue('Starting Adaptive Cruise Control Module...')
        #textBox.SetValue('Starting Auto Parking Module...')
        
    
    def on_button1(self, event):
        print('Starting Point-to-Point Navigation Module')
        textBox = wx.TextCtrl(self, value = "Starting Point-to-Point Navigation Module...",style = wx.TE_READONLY|wx.TE_MULTILINE, pos =(250, 300), size =(1400, 300))
    
    def on_button2(self, event):
        print('Starting Adaptive Cruise Control Module')
        textBox = wx.TextCtrl(self, value = "Starting Adaptive Cruise Control Module...",style = wx.TE_READONLY|wx.TE_MULTILINE, pos =(250, 300), size =(1400, 300))
        
    def on_button3(self, event):
        print('Starting Auto Parking Module')
        textBox = wx.TextCtrl(self, value = "Starting Auto Parking Module...",style = wx.TE_READONLY|wx.TE_MULTILINE, pos =(250, 300), size =(1400, 300))
        
    def on_exitButton(self, event):
        self.GetParent().Close()

class MyFrame(wx.Frame):
    def __init__(self):
        super().__init__(None, title='SMART Car II')
        panel = MyPanel(self)
        #self.Show()
        self.ShowFullScreen(True)

if __name__ == '__main__':
    app = wx.App(redirect=False)
    frame = MyFrame()
    frame.SetSize(0,0,640,480)
    frame.Centre()
    app.MainLoop()