# This is the Abstract layer of Display Driver 

# Nemuisan said...
# If Defined NO_TOUCH_CTRL, 
# Touchpanel Driver is forcibly reject.

ifeq ($(USE_DISPLAY),USE_ILI932x_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ili932x.c
 
else ifeq ($(USE_DISPLAY),USE_ILI932x_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ili932x.c
 
else ifeq ($(USE_DISPLAY),USE_ST7735_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/st7735.c
 
else ifeq ($(USE_DISPLAY),USE_ST7735_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/st7735.c
 
else ifeq ($(USE_DISPLAY),USE_SSD1339_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1339.c
 
else ifeq ($(USE_DISPLAY),USE_SSD1339_SPI_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1339.c

else ifeq ($(USE_DISPLAY),USE_SSD1283A_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1283a.c
 
else ifeq ($(USE_DISPLAY),USE_SSD1332_SPI_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1332.c
 
else ifeq ($(USE_DISPLAY),USE_SSD2119_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd2119.c
 
else ifeq ($(USE_DISPLAY),USE_SSD2119_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd2119.c
 
else ifeq ($(USE_DISPLAY),USE_SSD1289_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1289.c
 
else ifeq ($(USE_DISPLAY),USE_R61509x_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/r61509x.c
 
else ifeq ($(USE_DISPLAY),USE_R61509x_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/r61509x.c
 
else ifeq ($(USE_DISPLAY),USE_HX8347x_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8347x.c
 
else ifeq ($(USE_DISPLAY),USE_HX8340B_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8340b.c
 
else ifeq ($(USE_DISPLAY),USE_HX8340B_SPI_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8340b.c
 
else ifeq ($(USE_DISPLAY),USE_HX8340BN_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8340bn.c
 
else ifeq ($(USE_DISPLAY),USE_HX8312A_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8312a.c
 
else ifeq ($(USE_DISPLAY),USE_HX8352x_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8352x.c
 
else ifeq ($(USE_DISPLAY),USE_HX8352x_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8352x.c

else ifeq ($(USE_DISPLAY),USE_ILI9481_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9481.c

else ifeq ($(USE_DISPLAY),USE_ILI9481_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9481.c

else ifeq ($(USE_DISPLAY),USE_ILI9327_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9327.c
 
else ifeq ($(USE_DISPLAY),USE_ILI9225x_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9225x.c

else ifeq ($(USE_DISPLAY),USE_ILI9225x_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9225x.c
 
else ifeq ($(USE_DISPLAY),USE_ILI9132_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9132.c
 
else ifeq ($(USE_DISPLAY),USE_TL1771_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/tl1771.c
 
else ifeq ($(USE_DISPLAY),USE_S1D19122_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/s1d19122.c
 
else ifeq ($(USE_DISPLAY),USE_R61514S_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/r61514s.c
 
else ifeq ($(USE_DISPLAY),USE_ST7732_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/st7732.c
 
else ifeq ($(USE_DISPLAY),USE_S6D0128_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d0128.c
 
else ifeq ($(USE_DISPLAY),USE_S6D0129_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d0129.c
 
else ifeq ($(USE_DISPLAY),USE_S6D0129_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d0129.c
 
else ifeq ($(USE_DISPLAY),USE_S6D0144_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d0144.c
 
else ifeq ($(USE_DISPLAY),USE_S6D0144_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d0144.c
 
else ifeq ($(USE_DISPLAY),USE_SEPS525_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/seps525.c
 
else ifeq ($(USE_DISPLAY),USE_SEPS525_SPI_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/seps525.c

else ifeq ($(USE_DISPLAY),USE_SSD1963_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1963.c
 
else ifeq ($(USE_DISPLAY),USE_ST7735R_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/st7735r.c
 
else ifeq ($(USE_DISPLAY),USE_ST7735R_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/st7735r.c
 
else ifeq ($(USE_DISPLAY),USE_S6E63D6_OLED)
CFILES += \
 $(DISPLAY_DRV_SRC)/s6e63d6.c
 
else ifeq ($(USE_DISPLAY),USE_S6E63D6_SPI_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6e63d6.c
 
else ifeq ($(USE_DISPLAY),USE_HX5051_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx5051.c
 
else ifeq ($(USE_DISPLAY),USE_HX5051_SPI_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx5051.c
 
else ifeq ($(USE_DISPLAY),USE_LGDP4511_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/lgdp4511.c
 
else ifeq ($(USE_DISPLAY),USE_LGDP452x_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/lgdp452x.c
 
else ifeq ($(USE_DISPLAY),USE_SSD1286A_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1286a.c
 
else ifeq ($(USE_DISPLAY),USE_S1D19105_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/s1d19105.c
 
else ifeq ($(USE_DISPLAY),USE_ILI9163x_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9163x.c
 
else ifeq ($(USE_DISPLAY),USE_ILI9163x_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9163x.c
 
else ifeq ($(USE_DISPLAY),USE_REL225L01_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/rel225l01.c
 
else ifeq ($(USE_DISPLAY),USE_HD66772_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hd66772.c
 
else ifeq ($(USE_DISPLAY),USE_HX8347x_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8347x.c
 
else ifeq ($(USE_DISPLAY),USE_SPFD54124_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/spfd54124.c
 
else ifeq ($(USE_DISPLAY),USE_SPFD54124_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/spfd54124.c
 
else ifeq ($(USE_DISPLAY),USE_ILI934x_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ili934x.c
 
else ifeq ($(USE_DISPLAY),USE_ILI934x_SPI_TFT)
ifeq ($(EVAL_BOARD),USE_32F429IDISCOVERY)
 CFILES += \
 $(DISPLAY_DRV_SRC)/ili934x.c
else
 USE_TOUCH_CTRL = NO_TOUCH_CTRL
 CFILES += \
 $(DISPLAY_DRV_SRC)/ili934x.c
endif

else ifeq ($(USE_DISPLAY),USE_C1L5_06_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/c1l5_06.c
 
else ifeq ($(USE_DISPLAY),USE_S6B33B6x_CSTN)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6b33b6x.c
 
else ifeq ($(USE_DISPLAY),USE_S6B33B6x_SPI_CSTN)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6b33b6x.c
 
else ifeq ($(USE_DISPLAY),USE_HX8345A_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8345a.c
 
else ifeq ($(USE_DISPLAY),USE_R61526_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/r61526.c
 
else ifeq ($(USE_DISPLAY),USE_S6D0117_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d0117.c

else ifeq ($(USE_DISPLAY),USE_HX8309A_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8309a.c
 
else ifeq ($(USE_DISPLAY),USE_SSD1351_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1351.c
 
else ifeq ($(USE_DISPLAY),USE_SD1351_SPI_OLED)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/ssd1351.c
 
else ifeq ($(USE_DISPLAY),USE_C1E2_04_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/c1e2_04.c

else ifeq ($(USE_DISPLAY),USE_D51E5TA7601_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/d51e5ta7601.c

else ifeq ($(USE_DISPLAY),USE_HX8357A_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8357a.c

else ifeq ($(USE_DISPLAY),USE_UPD161704A_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/upd161704a.c
 
else ifeq ($(USE_DISPLAY),USE_UPD161704A_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/upd161704a.c

else ifeq ($(USE_DISPLAY),USE_ST7787_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/st7787.c

else ifeq ($(USE_DISPLAY),USE_SPFD54126_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/spfd54126.c

else ifeq ($(USE_DISPLAY),USE_R61503U_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/r61503u.c

else ifeq ($(USE_DISPLAY),USE_HX8310A_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8310a.c

else ifeq ($(USE_DISPLAY),USE_HX8353x_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8353x.c

else ifeq ($(USE_DISPLAY),USE_HX8353x_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8353x.c

else ifeq ($(USE_DISPLAY),USE_S6D0154_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d0154.c
 
else ifeq ($(USE_DISPLAY),USE_ILI9342_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9342.c
 
else ifeq ($(USE_DISPLAY),USE_LG4538_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/lg4538.c
 
else ifeq ($(USE_DISPLAY),USE_LG4538_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/lg4538.c

else ifeq ($(USE_DISPLAY),USE_NT35510_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/nt35510.c

else ifeq ($(USE_DISPLAY),USE_BD663474_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/bd663474.c

else ifeq ($(USE_DISPLAY),USE_S6D02A1_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d02a1.c

else ifeq ($(USE_DISPLAY),USE_S6D05A1_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d05a1.c

else ifeq ($(USE_DISPLAY),USE_ILI9341_RGB_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/ili9341_rgb.c

else ifeq ($(USE_DISPLAY),USE_HX8369A_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8369a.c

else ifeq ($(USE_DISPLAY),USE_OTM8009A_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/otm8009a.c

else ifeq ($(USE_DISPLAY),USE_LGDP4551_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/lgdp4551.c

else ifeq ($(USE_DISPLAY),USE_S6D04D1_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/s6d04d1.c

else ifeq ($(USE_DISPLAY),USE_TL1763_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/tl1763.c
 
else ifeq ($(USE_DISPLAY),USE_RM68110_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/rm68110.c

else ifeq ($(USE_DISPLAY),USE_NT35582_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/nt35582.c

else ifeq ($(USE_DISPLAY),USE_HX8367A_SPI_TFT)
USE_TOUCH_CTRL = NO_TOUCH_CTRL
CFILES += \
 $(DISPLAY_DRV_SRC)/hx8367a.c

else ifeq ($(USE_DISPLAY),USE_RK043FN48H_RGB_TFT)
CFILES += \
 $(DISPLAY_DRV_SRC)/rk043fn48h_rgb.c


else
 $(error DISPLAY DRIVER IS NOT DEFINED!!)

endif
