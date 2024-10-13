file(GLOB_RECURSE SOURCES "*.cpp")
idf_component_register( SRCS ${SOURCES}
                        INCLUDE_DIRS "." "../include"
                        REQUIRES arduino freertos nvs_flash
                        )

