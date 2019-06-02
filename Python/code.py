import tkinter as tk
from tkinter import ttk
import tkinter.messagebox

# 实例化object，建立窗口window
window = tk.Tk()

# 给窗口的可视化起名字
window.title('User Interface Design')

# 设定窗口的大小(长 * 宽)
window.geometry('1000x650')  # 这里的乘是小x

tk.Label(window, text='Title (Mr, Ms, Dr etc):', font=('Times', 14)).place(x=10, y=8)
titleselect = ttk.Combobox(window, width=23)
titleselect['values'] = ('Mr', 'Ms', 'Dr') 
titleselect.set('**Please Select**')
titleselect.place(x=750, y=10)

tk.Label(window, text='Name:', font=('Times', 14)).place(x=10, y=48)
first_name = tk.Entry(window, font=('Times', 14))
first_name.place(x=750, y=50)

tk.Label(window, text='Job title:', font=('Times', 14)).place(x=10, y=88)
job_title = tk.Entry(window, font=('Times', 14))
job_title.place(x=750, y=90)

tk.Label(window, text='Institution/Organisation:', font=('Times', 14)).place(x=10, y=128)
IO = tk.Entry(window, font=('Times', 14))
IO.place(x=750, y=130)

tk.Label(window, text='County:', font=('Times', 14)).place(x=10, y=168)
country = ttk.Combobox(window, width=23)
country['values'] = ('China', 'United States')
country.set('**Please Select**')
country.place(x=750, y=170)

tk.Label(window, text='City:', font=('Times', 14)).place(x=10, y=208)
city = tk.Entry(window, font=('Times', 14))
city.place(x=750, y=210)

tk.Label(window, text='Number and Street:', font=('Times', 14)).place(x=10, y=248)
nands = tk.Entry(window, font=('Times', 14))
nands.place(x=750, y=250)

tk.Label(window, text='Zip Code/Postal Code:', font=('Times', 14)).place(x=10, y=288)
zip_pos = tk.Entry(window, font=('Times', 14), width='6')
zip_pos.place(x=750, y=290)

tk.Label(window, text='Email:', font=('Times', 14)).place(x=10, y=328)
email = tk.Entry(window, font=('Times', 14))
email.place(x=750, y=330)

tk.Label(window, text='Home phone:', font=('Times', 14)).place(x=10, y=368)
homephofirst = tk.StringVar() 
homepho1 = tk.Entry(window, font=('Times', 14), width='6', textvariable=homephofirst)
homepho1.place(x=750, y=370)
homephosecond = tk.StringVar() 
homepho2 = tk.Entry(window, font=('Times', 14), width='11', textvariable=homephosecond)
homepho2.place(x=827, y=370)

tk.Label(window, text='Work phone:', font=('Times', 14)).place(x=10, y=408)
workphofirst = tk.StringVar() 
workpho1 = tk.Entry(window, font=('Times', 14), width='6', textvariable=workphofirst)
workpho1.place(x=750, y=410)
workphosecond = tk.StringVar() 
workpho2 = tk.Entry(window, font=('Times', 14), width='11', textvariable=workphosecond)
workpho2.place(x=827, y=410)

tk.Label(window, text='Fax:', font=('Times', 14)).place(x=10, y=448)
faxfirst = tk.StringVar() 
fax1 = tk.Entry(window, font=('Times', 14), width='6', textvariable=faxfirst)
fax1.place(x=750, y=450)
faxsecond = tk.StringVar() 
fax2 = tk.Entry(window, font=('Times', 14), width='11', textvariable=faxsecond)
fax2.place(x=827, y=450)

tk.Label(window, text='How did you find out about this Web site:', font=('Times', 14)).place(x=10, y=488)
how = ttk.Combobox(window, width=23)
how.set('**Please Select**')
how.place(x=750, y=490)

tk.Label(window, text='Please select the option which most closely describes you as a customer:', font=('Times', 14)).place(x=10, y=528)
please = ttk.Combobox(window, width=23)
please.set('**Please Select**')
please.place(x=750, y=530)

tk.Label(window, text='Other:', font=('Times', 14)).place(x=10, y=568)
homepho1 = tk.Entry(window, font=('Times', 14))
homepho1.place(x=750, y=570)


def usr_submit():
    if (len(workphofirst.get()) != 3):
        tk.messagebox.showerror(title='error', message='workphonefirsterror')
        return
    if (len(workphosecond.get()) != 8):
        tk.messagebox.showerror(title='error', message='workphoneseconderror')
        return
    if (len(homephofirst.get()) != 3):
        tk.messagebox.showerror(title='error', message='homephonefirsterror')
        return
    if (len(homephosecond.get()) != 8):
        tk.messagebox.showerror(title='error', message='homephoneseconderror')
        return
    if (len(faxfirst.get()) != 3):
        tk.messagebox.showerror(title='error', message='faxfirsterror')
        return
    if (len(faxsecond.get()) != 8):
        tk.messagebox.showerror(title='error', message='faxseconderror')
        return
    tk.messagebox.showinfo(title='prompt', message='fill completed!')


bt_login = tk.Button(window, text='submit', command=usr_submit)
bt_login.place(x=480, y=610)



# 主窗口循环显示
window.mainloop()