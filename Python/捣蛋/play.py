import pyautogui
import random
import keyboard

print("点击esc可以退出")

while 1:
    x = random.randint(1, 2048)
    y = random.randint(1, 2048)
    pyautogui.click(x, y)
    pyautogui.click(x, y)
    if keyboard.is_pressed('esc'):
        break
