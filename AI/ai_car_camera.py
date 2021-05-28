
import sensor
import image
import lcd
import time
import utime
from machine import UART
from Maix import GPIO
from fpioa_manager import *

fm.register(34,fm.fpioa.UART1_TX)
fm.register(35,fm.fpioa.UART1_RX)
uart_out = UART(UART.UART1, 4800, 8, None, 1, timeout=1000, read_buf_len=4096)

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.run(1)

target_lab_green_threshold = (0,   80,  -90,   -30,   50,   100)
target_lab_red_threshold = (0,   80,  20,   100,   20,   100)
target_lab_white_threshold = (90,   100,  -10,   10, -10,   10)
while True:
    img=sensor.snapshot()
    zebra = img.find_blobs([target_lab_white_threshold], x_stride = 2, y_stride = 2, pixels_threshold = 100, merge = True, margin = 20)
    red_blob = img.find_blobs([target_lab_red_threshold], x_stride = 2, y_stride = 2, pixels_threshold = 100, merge = True, margin = 20)
    green_blob = img.find_blobs([target_lab_green_threshold], x_stride = 2, y_stride = 2, pixels_threshold = 100, merge = True, margin = 20)
    max_area = 0
    object_code = "3"
    if zebra:
        for b in zebra:
            if b.area() > max_area:
                max_area = b.area()
                target = b
                object_code = "2"
    if green_blob:
        for b in green_blob:
            if b.area() > max_area:
                max_area = b.area()
                target = b
                object_code = "1"
    if red_blob:
        for b in red_blob:
            if b.area() > max_area:
                max_area = b.area()
                target = b
                object_code = "3"

    uart_out.write(object_code)
    print(object_code)
