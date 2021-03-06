#include "../include/scop.h"

// int 			load_all_textures(t_sdl *s)
// {
// 	if (!(s->canvas = SDL_CreateTexture(s->renderer,
// 								SDL_PIXELFORMAT_ARGB8888,
// 								SDL_TEXTUREACCESS_STATIC,
// 								s->win_w, s->win_h)))
// 	{
// 		ft_putendl_fd("failed to initiate texture in SDL", 2);
// 		return (0);
// 	}
// 	s->textures[0] = load_texture("src/img/dark_pixel2.png", s);
// 	s->textures[1] = load_texture("src/img/dark_pixel.png", s);
// 	s->textures[2] = load_texture("src/img/rama.png", s);
// 	return (1);
// }

void				set_bg(t_sdl *s)
{

	SDL_UpdateTexture(s->canvas, NULL, s->pixels, s->win_w << 2);
	SDL_RenderClear(s->renderer);
	SDL_RenderCopy(s->renderer, s->canvas, NULL, NULL);
	SDL_RenderPresent(s->renderer);
}

int	is_quit(SDL_Event e)
{
	return (e.type == SDL_QUIT || (e.type == SDL_WINDOWEVENT &&
			e.window.event == SDL_WINDOWEVENT_CLOSE) ||
			(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE));
}

void	run_ui(t_sdl *s)
{
	int			running;
	SDL_Event	evt;

	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&evt))
			if (is_quit(evt))
				running = 0;
			
			// else if (evt.type == SDL_KEYDOWN)
			// 	on_event(s, &evt);
			// else if (evt.type == SDL_KEYUP)
			// 	off_event(s, &evt);
			// else if (evt.type == SDL_MOUSEBUTTONDOWN)
			// 	check_pressing(s, evt.button.x, evt.button.y);
		set_bg(s);
	}
}



int 			sdl_init_everything(t_sdl *s)
{

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		ft_putendl_fd("failed to initiate SDL", 2);
		return (0);
	}
	s->win_w = 400;
	s->win_h = 400;
	s->win = SDL_CreateWindow("SCOP",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		s->win_w, s->win_h, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_ALLOW_HIGHDPI);
	if (s->win == NULL)
	{
		ft_putendl_fd("failed to initiate WIN in SDL", 2);
		return (0);
	}
	s->renderer = SDL_CreateRenderer(s->win, -1, SDL_RENDERER_ACCELERATED);
	if (s->renderer == NULL)
	{
		ft_putendl_fd("failed to initiate renderer in SDL", 2);
		return (0);
	}

	SDL_RenderSetLogicalSize(s->renderer, s->win_w, s->win_h);
	SDL_SetRenderDrawColor(s->renderer, 0, 255, 0, 255);
	s->pixels = malloc(sizeof(int) * (s->win_w * s->win_h));
	return (1);
}



// int 			run_ui(t_sdl *s)
// {
// 	int running = 1;
// 	char flag = 0;

// //	size_t			job_size = s->win_w * s->win_h;

// 	printf("initioated succesfully");
// //	init_kernel(s);

// //
// 	while (running)
// 	{
// 		SDL_Event evt;
// 		while (SDL_PollEvent(&evt))
// 		{
// 			if (evt.type == SDL_QUIT || (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE))
// 				running = 0;
// 			else if (evt.type == SDL_KEYDOWN )
// 			{
// 				if (evt.key.keysym.sym == SDLK_UP)
// 					flag = 1;
// 				else if (evt.key.keysym.sym == SDLK_DOWN)
// 					flag = 2;
// 				else if (evt.key.keysym.sym == SDLK_LEFT)
// 					flag = 3;
// 			}
// 			else if (evt.type == SDL_MOUSEBUTTONDOWN)
// 			{
// 				check_pressing(s, evt.button.x, evt.button.y);
// 				render_buttons(s);
// 			}
// 		}

// //		for (int i = 0; i < 2; i++)
// //			rt_cl_push_task(&s->extended, &job_size);
// //		rt_cl_push_task(&s->smooth, &job_size);
// // 		rt_cl_device_to_host(&s->info, s->out, pixels, job_size * sizeof(int));

// //		clSetKernelArg(s->kernel.kernel, 3, sizeof(cl_uint), &s->samples);
// //		rt_cl_push_task(&s->kernel, &job_size);
// //
// //		rt_cl_device_to_host(&s->info, s->pixels_mem, s->pixels, job_size * sizeof(int));
// //
// //		rt_cl_join(&s->info);

// 		set_bg(s);
//		SDL_RenderPresent(s->renderer);
		// if (s->file != NULL && s->go)
		// {
		// 	s->go = 0;
		// 	// start_parsing(s);
		// }
		// if (flag == 1)
		// {
		// 	s->surf = SDL_LoadBMP(tinyfd_openFileDialog("Please choose .bmp file", "", 2, lFilterPatterns, NULL, 0));
		// 	txt = SDL_CreateTextureFromSurface(s->renderer, s->surf);
		// 	SDL_FreeSurface(s->surf);
		// 	SDL_RenderCopy(s->renderer, txt, NULL, NULL);
		// 	SDL_RenderPresent(s->renderer);
  //     			// SDL_Delay(2000);
		// }
		// else if (flag == 2)
		// {
		// 	// s->surf = SDL_LoadBMP("tigr.bmp");
		// 	// BlueShapes = SDL_CreateTextureFromSurface(s.renderer, s->surf);
		// 	// SDL_FreeSurface(s->surf);
		// 	// SDL_RenderCopy(s.renderer, BlueShapes, &SrcR, &DestR);
		// 	// SDL_RenderPresent(s.renderer);
		// }
		// if (flag == 3)
		// {
		// 	// SDL_Surface* screenSurface = NULL;
		// 	// s->surf = IMG_Load(tinyfd_openFileDialog("Please choose .bmp file", "", 2, lFilterPatterns, NULL, 0));
		// 	// SDL_Texture* BlueShapes = SDL_CreateTextureFromSurface(s->renderer, s->surf);
		// 	// SDL_FreeSurface(s->surf);
		// 	// SDL_RenderCopy(s->renderer, load_texture(icons[i], s), NULL, NULL);
		// 	// SDL_RenderPresent(s.renderer);
		// }
		// flag = 0;
		// SDL_RenderClear(s->renderer);
		// s->surf = SDL_CreateRGBSurfaceFrom((void*)s->data,
		// 	a->scene->image_width, a->scene->image_height, 32,
		// 	a->scene->image_width * 4, 0, 0, 0, 0);
		// s->surf = SDL_LoadBMP("tigr.bmp");
		// set_panels(s->renderer, s->surf);
		// s->surf = SDL_CreateRGBSurface(0, 400, 800, 32, 48, 214, 250, 0);
		// txt = SDL_CreateTextureFromSurface(s->renderer, s->surf);
		// txt = load_texture("folder.png", s);
		// SDL_RenderCopy(s->renderer, load_texture("gal.png", s), NULL, NULL);
// 		SDL_RenderPresent(s->renderer);
// 	}
// 	SDL_FreeSurface(s->surf);
// 	rt_cl_free_kernel(&s->kernel);
// //	rt_cl_free_kernel(&s->primary);
// //	rt_cl_free_kernel(&s->extended);
// 	rt_cl_free(&s->info);
// 	SDL_DestroyTexture(s->canvas);
// 	SDL_DestroyRenderer(s->renderer);
// 	SDL_DestroyWindow(s->win);
// 	SDL_Quit();
// 	return (1);
// }