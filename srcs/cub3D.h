#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../cubadd/minilibx/mlx.h"
# include "../cubadd/get_next_line/get_next_line.h"
# include "../cubadd/libft/libft.h"
# define K_A 0
# define K_S 1
# define K_D 2
# define K_W 13
# define K_ESC 53
# define ARRL 123
# define ARRR 124
# define BLUE 4876733
# define RED 15412998
# define GREEN 7921807
# define YELLOW 16169275

typedef struct s_win
{
	int		width;
	int		height;
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
}				t_win;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		length;
	int		bpp;
	int		endian;
	int		width;
	int		heigth;
}				t_img;

typedef struct s_bmp
{
	char		*massiv;
	int			size_file;
	int			app_spe;
	int			data_offset;
	int			size_dib;
	int			width;
	int			heigth;
	short int	planes;
	short int	bpp;
	int			*data_ptr;
	double		trash;
}				t_bmp;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_param
{
	int		width;
	int		heigth;
	char	r;
	char	*no;
	char	*ea;
	char	*so;
	char	*we;
	int		f;
	int		c;
	char	*s;
	int		save;
	int		end;
	int		length;
	char	player;
	int		flag;
	int		max;
	char	**map;
	int		red;
	int		g;
	int		b;
}				t_param;

typedef struct s_spr
{
	double	transformy;
	int		spritescreenx;
	int		spritew;
	int		spriteh;
	int		drawstartx;
	int		drawendx;
	int		drawstarty;
	int		drawendy;
}				t_spr;

typedef struct s_all
{
	int		width;
	int		heigth;
	t_win	*img;
	t_win	*text_n;
	t_win	*text_s;
	t_win	*text_e;
	t_win	*text_w;
	t_win	*text_sp;
	t_param	*list;
	char	**map;
	char	*n_path;
	char	*s_path;
	char	*e_path;
	char	*w_path;
	void	*mlx;
	void	*win;
	int		floor_color;
	char	*sprite_path;
	int		n_sprites;
	int		ceiling_color;
	double	rspeed;
	double	mspeed;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	int		mapx;
	int		mapy;
	double	camerax;
	int		key_left;
	int		key_w;
	int		key_back;
	int		key_rigth;
	int		key_rr;
	int		key_rl;
	int		x;
	int		stepx;
	int		stepy;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		side;
	double	sidedistx;
	double	sidedisty;
	char	hitside;
	double	*zbuffer;
	t_point	*sprites_coords;
}				t_all;

int		get_next_line(int fd, char **line);
int		ifn(char *str);
void	check_first(t_param *list, char **s, int i);
void	ft_check_r(char *line, t_param *list);
void	ft_cycle(t_param *list, int len, char **s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*putsave(char *save);
char	*putline(char *str);
void	ft_analyse_map(char **s, t_param *list, int len);
int		ft_check_empty_line(char **s, int i);
void	ft_parser(char **s, t_param *list, int len);
int		ft_checking_one(char *line, t_param *list, int j);
int		ft_checking_two(char *line, t_param *list, int j);
void	init_list(t_param **list);
t_all	*init_all(t_param *list, char **s);
double	init_dir(char player, int flag);
double	init_plane(char player, int flag);
void	ft_errors(int fd);
void	ft_create_my_map(char **s, t_param *list);
void	movings_player(t_all *s);
int		ft_check_f_or_c(char *line, t_param *list, int i, int flag);
char	cub_hitside(t_all *all);
void	draw_texture(t_all *s, int start, int end, int lineheight);
void	draw_vertical(t_all *s, int y_start, int y_end);
int		finder(char *str, char c);
void	draw_background(t_all *all);
void	perform_raycasting(t_all *stock);
int		key_pressed(int keycode, void *param);
int		key_released(int keycode, void *param);
int		rendering(void *param);
void	ft_bmp(t_all *stock);
void	free_all(t_all *stock);
void	draw_sprites(t_all *s);
void	my_mlx_destroy_image(t_win *img);
void	my_mlx_push_img(t_win *img);
t_win	*my_mlx_xpm_to_img(void *mlx_ptr, char *path);
t_win	*my_mlx_new_image(void *mlx_ptr, void *win_ptr, int width, int height);
void	init_all_sprites(t_all *s);
void	n_sprites(t_all *all, char **map);
void	sort_sprites(t_all *all);
#endif