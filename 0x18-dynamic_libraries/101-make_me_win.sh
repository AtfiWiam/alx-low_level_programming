#!/bin/bash
wget -P /tmp https://github.com/AtfiWiam/alx-low_level_programming/blob/e58dc35ecea2db15dee6d84332d58be1f9d0c324/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD=/tmp/libgiga.so
