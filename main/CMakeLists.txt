

idf_component_register(SRCS 
                            "app_main.c"

                            "src/ds_system_data.c"

                            "src/hal/ds_timer.c"
                            "src/hal/ds_nvs.c"
                            "src/hal/ds_gpio.c"
                            "src/hal/ds_i2c.c"
                            "src/hal/ds_spi.c"

                            "src/fs/ds_spiffs.c"

                            "src/driver/ds_ft6336.c"
                            "src/driver/ds_screen.c"

                            "src/net/ds_wifi_ap.c"
                            "src/net/ds_http_server.c"
                            "src/net/ds_wifi_sta.c"
                            "src/net/ds_wifi_scan.c"
                            "src/net/ds_http_request.c"

                            "src/draw/ds_font.c"
                            "src/draw/ds_paint.c"
                    
                       INCLUDE_DIRS 
                            "."
                            "./include"
                            "./include/draw"
                            "./include/hal"
                            "./include/fs"
                            "./include/driver"
                            "./include/data"
                            "./include/net"
                        
                        EMBED_FILES 
                            "./html/favicon.ico"
                            "./html/setting.html"

                        EMBED_TXTFILES
                            "https_pem/server_root_cert.pem"
                            "https_pem/server_root_cert_bilibili.pem"
                            )
