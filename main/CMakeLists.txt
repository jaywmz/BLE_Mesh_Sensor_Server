set(srcs "main.cpp"
        "board.c" "test_irremote.cpp")

idf_component_register(SRCS "${srcs}"
                    INCLUDE_DIRS  ".")
