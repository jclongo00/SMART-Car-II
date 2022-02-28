# File:      unserInterface.py
# Date:      2/27/2022
# Version:   1.2
import wx

class MyPanel(wx.Panel):
    
    def __init__(self, parent):
        super().__init__(parent)
        
        self.textBox = wx.TextCtrl(self, value = "",style = wx.TE_READONLY|wx.TE_MULTILINE, size =(1000, -1))
        
        img = wx.Image("40light_off.jpg")
        self.image1 = wx.StaticBitmap(self, bitmap=wx.Bitmap(img))
        self.image2 = wx.StaticBitmap(self, bitmap=wx.Bitmap(img))
        self.image3 = wx.StaticBitmap(self, bitmap=wx.Bitmap(img))
        
        button1 = wx.Button(self, label='Point-to-Point Navigation', size =(300, 40))
        button1.Bind(wx.EVT_BUTTON, self.on_button1)
        
        button2 = wx.Button(self, label='Adaptive Cruise Control', size =(300, 40))
        button2.Bind(wx.EVT_BUTTON, self.on_button2)
        
        button3 = wx.Button(self, label='Auto Parking', size =(300, 40))
        button3.Bind(wx.EVT_BUTTON, self.on_button3)
        
        stopButton = wx.Button(self, label='Stop', size =(300, 40))
        stopButton.Bind(wx.EVT_BUTTON, self.on_stopButton)
        
        exitButton = wx.Button(self, label='Exit', size =(150, 40))
        exitButton.Bind(wx.EVT_BUTTON, self.on_exitButton)
        
        main_Sizer = wx.BoxSizer(wx.VERTICAL)
        hsizer1 = wx.BoxSizer(wx.HORIZONTAL)
        hsizer2 = wx.BoxSizer(wx.HORIZONTAL)
        hsizer3 = wx.BoxSizer(wx.HORIZONTAL)
        
        hsizer1.Add(self.image1, 0, wx.ALL, 5)
        hsizer1.Add(button1, 0, wx.ALL, 5)
        main_Sizer.Add(hsizer1, 0, wx.ALIGN_CENTER)
        
        hsizer2.Add(self.image2, 0, wx.ALL, 5)
        hsizer2.Add(button2, 0, wx.ALL, 5)
        main_Sizer.Add(hsizer2, 0, wx.ALIGN_CENTER)
        
        hsizer3.Add(self.image3, 0, wx.ALL, 5)
        hsizer3.Add(button3, 0, wx.ALL, 5)
        main_Sizer.Add(hsizer3, 0, wx.ALIGN_CENTER)

        main_Sizer.Add(self.textBox, 0, wx.ALIGN_CENTER, 5)
        main_Sizer.Add(stopButton, 0, wx.ALIGN_CENTER, 5)
        main_Sizer.Add(exitButton, 0, wx.ALIGN_CENTER, 5)
        
        self.SetSizer(main_Sizer)
        
        #textBox.SetValue('Starting Point-to-Point Navigation Module...')
        #textBox.SetValue('Starting Adaptive Cruise Control Module...')
        #textBox.SetValue('Starting Auto Parking Module...')
        
    
    def on_button1(self, event):
        self.textBox.SetValue('Starting Point-to-Point Navigation Module...')
        off_img = wx.Image("40light_off.jpg")
        on_img = wx.Image("40light_on.jpg")
        self.image1.SetBitmap(wx.Bitmap(on_img))
        self.image2.SetBitmap(wx.Bitmap(off_img))
        self.image3.SetBitmap(wx.Bitmap(off_img))
        self.Refresh()
    
    def on_button2(self, event):
        self.textBox.SetValue('Starting Adaptive Cruise Control Module...')
        off_img = wx.Image("40light_off.jpg")
        on_img = wx.Image("40light_on.jpg")
        self.image1.SetBitmap(wx.Bitmap(off_img))
        self.image2.SetBitmap(wx.Bitmap(on_img))
        self.image3.SetBitmap(wx.Bitmap(off_img))
        self.Refresh()
        
    def on_button3(self, event):
        self.textBox.SetValue('Starting Auto Parking Module...')
        off_img = wx.Image("40light_off.jpg")
        on_img = wx.Image("40light_on.jpg")
        self.image1.SetBitmap(wx.Bitmap(off_img))
        self.image2.SetBitmap(wx.Bitmap(off_img))
        self.image3.SetBitmap(wx.Bitmap(on_img))
        self.Refresh()
        
    def on_stopButton(self, event):
    	self.textBox.SetValue('Stopping...')
    	off_img = wx.Image("40light_off.jpg")
    	self.image1.SetBitmap(wx.Bitmap(off_img))
    	self.image2.SetBitmap(wx.Bitmap(off_img))
    	self.image3.SetBitmap(wx.Bitmap(off_img))
    	self.Refresh()
        
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
