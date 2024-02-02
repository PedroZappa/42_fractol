define main
	display argc
	display display
end

define ft_init_display
	display *display
	display *display->img 
end

## Start at amin
# fs cmd
# break main
# run "mandelbrot"
# main


## Start in ft_init_display
fs cmd
break ft_init_display
run "mandelbrot"
ft_init_display
