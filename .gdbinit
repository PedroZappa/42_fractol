define rfr
	refresh
end

define main
	display argc
	display display
end

define ft_args
	display display
	display argc
	display argv
end

define ft_help_flag
	display argc
	display argv
	display i
end

define ft_select_fractal
	display argc
	display name
	display *display
	display display->set
	display display->name
	display display->iter
end

define ft_set_complex
	display *display
	display argc
	display argv[3]
	display argv[4]
	display display->c_julia.r
	display display->c_julia.i
	display display->iter
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

define render_julia
	display *d
	display d->z
	display d.escape
	display z_tmp
	display color
	display i
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

define ft_kill_handle
	display *display
end

define vgdb
	target remote | vgdb
end

define mchk
	monitor leak_check full reachable any
end


# set logging enabled on

## Start @ main
# fs cmd
# break main
# run "julia" 42 0.3 1
# main

## Start @ ft_args
# fs cmd
# break ft_args
# run "julia" 42 0.3 1
# ft_args

## Start @ ft_select_fractal
# fs cmd
# break ft_select_fractal
# run "julia" 42 0.3 1
# ft_select_fractal

## Star @ ft_set_complex
# fs cmd
# break ft_set_complex
# run "julia" 43 0.1 0.7
# ft_set_complex

## Start @ ft_init_display
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

# Star @ render_julia
fs cmd
break render_julia
run "julia" 88 0.3 1
render_julia
rfr


# Start @ ft_get_pixel
# fs cmd
# break ft_get_pixel
# run "mandelbrot"
# ft_get_pixel
# next
# rfr

# Start @ ft_put_pixel
# fs cmd
# break ft_put_pixel
# run "mandelbrot"
# ft_put_pixel
