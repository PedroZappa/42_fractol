define rfr
	refresh
end

define main
	display argc
	display display
end

define ft_init_display
	display *display
	display *display->escape 
	display *display->iter 
end

define ft_init_data
	display *display
	display *display->img 
end

define ft_render
	display *display
	display x
	display y
end

define ft_get_pixel
	display *display
	display display->z
	display display->z.r
	display display->z.i
	display display->c.r
	display display->c.i

	display x
	display y
	display color
end

define ft_scale
	display unscaled_n
	display max
	display scaled_min
	display scaled_max
	display (((scaled_max - scaled_min) * unscaled_n / max) + scaled_min)
end


define ft_put_pixel
	display *img
	display *img->line_len
	display *img->bbp
	display x
	display y
	display color
	display offset
end

set logging enabled on

## Start @ main
# fs cmd
# break main
# run "mandelbrot"
# main

## Start in ft_init_display
# fs cmd
# break ft_init_display
# run "mandelbrot"
# ft_init_display

# Start @ ft_render
# fs cmd
# break ft_render
# run "mandelbrot"
# ft_render
# rfr

# Start @ ft_get_pixel
fs cmd
break ft_get_pixel
run "mandelbrot"
ft_get_pixel
next
rfr

# Start @ ft_put_pixel
# fs cmd
# break ft_put_pixel
# run "mandelbrot"
# ft_put_pixel
