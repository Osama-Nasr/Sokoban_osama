#include "Draw.h"

void Draw::TextStartingMenu(SDL_Surface* screen, SDL_Surface* eti)
{
	int black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int green = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int red = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int blue = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	DrawRectangle(screen, 4, 4, game::SCREEN_WIDTH - 8, game::SCREEN_HEIGHT - 8, red, blue);
	DrawSurface(screen, eti, game::SCREEN_WIDTH / 2, game::SCREEN_HEIGHT / 2 - 150);
	sprintf(text, "Welcome to Bullet Hell game");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 - 30, text);
	sprintf(text, "Press O for options");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2, text);
	sprintf(text, "Press S to start the game");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 + 30, text);
}

void Draw::TextOptions(SDL_Surface* screen, SDL_Surface* eti, double& enemyShootEverySEC, int activeOption, /*Player player,*/ int level, bool sequentail)
{
	int black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int green = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int red = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int blue = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	
	string SequetailText;
	if (sequentail == true)
		SequetailText = 'YES';
	else
		SequetailText = "NO";

	DrawRectangle(screen, 4, 4, game::SCREEN_WIDTH - 8, game::SCREEN_HEIGHT - 8, red, blue);
	DrawSurface(screen, eti, game::SCREEN_WIDTH / 2, game::SCREEN_HEIGHT / 2 - 180);
	DrawRectangle(screen, 150, screen->h / 2 - 30 + (activeOption * 30), 10, 10, red, red);
	sprintf(text, "Info catalog (press O to go back)");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 - 60, text);
	sprintf(text, "1. Speed of the player (0...10): %d", 9999);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 - 30, text);
	sprintf(text, "2. shooting from enemy every sec: %3.2f", enemyShootEverySEC);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2, text);
	sprintf(text, "3. level: %d", level + 1);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 + 30, text);
	sprintf(text, "4. Play sequentailly: %c", SequetailText);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 + 60, text);
}

void Draw::TextGame(SDL_Surface* screen, double worldTime, double fps, int numberOfHits, int numberOfgettingShooted, int points)
{
	int black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int green = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int red = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int blue = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
	int white = SDL_MapRGB(screen->format, 255, 255, 255);

	DrawRectangle(screen, 4, 4, game::SCREEN_WIDTH - 8, 36, white, blue);
	//            "template for the second project, elapsed time = %.1lf s  %.0lf frames / s"
	sprintf(text, "Esc - exit, elapsed time = %.1lf s  %.0lf frames / s", worldTime, fps);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text);
	//	      "Esc - exit, \030 - faster, \031 - slower"
	sprintf(text, "N - play again, hits: %d, got hit: %d, Total points: %d", numberOfHits, numberOfgettingShooted, points);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text);
}

void Draw::winMessage(SDL_Surface* screen) {

	int black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int green = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int red = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int blue = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);

	//DrawRectangle(screen, 4, 4, game::SCREEN_WIDTH - 8, 36, red, blue);
	////            "template for the second project, elapsed time = %.1lf s  %.0lf frames / s"
	//sprintf(text, "Esc - exit, elapsed time = %.1lf s  %.0lf frames / s", worldTime, fps);
	//DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 10, text);
	////	      "Esc - exit, \030 - faster, \031 - slower"
	//sprintf(text, "N - play again, hits: %d, got hit: %d, Total points: %d", numberOfHits, numberOfgettingShooted, points);
	//DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, 26, text);
}

void Draw::TextContinueMenu(SDL_Surface* screen, SDL_Surface* eti, int points)
{
	int black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	int green = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	int red = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	int blue = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);

	DrawRectangle(screen, 4, 4, game::SCREEN_WIDTH - 8, game::SCREEN_HEIGHT - 8, red, blue);
	DrawSurface(screen, eti, game::SCREEN_WIDTH / 2, game::SCREEN_HEIGHT / 2 - 150);
	sprintf(text, "Continue? Press c if so, or press ESC to exit, or press n for menu");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 - 30, text);
	sprintf(text, "Your score is %d", points);
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2, text);
	sprintf(text, "want to go to level 1 press 1 & level 2 press 2 and so on");
	DrawString(screen, screen->w / 2 - strlen(text) * 8 / 2, screen->h / 2 + 30, text);
}

void Draw::DrawString(SDL_Surface* screen, int x, int y, const char* text)
{
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while (*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		x += 8;
		text++;
	};
}

void Draw::DrawSurface(SDL_Surface* screen, SDL_Surface* sprite, int x, int y)
{
	SDL_Rect dest;
	dest.x = x - sprite->w / 2;
	dest.y = y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void Draw::DrawPixel(SDL_Surface* surface, int x, int y, Uint32 color)
{	
	int bpp = surface->format->BytesPerPixel;
	Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
	*(Uint32*)p = color;
}

void Draw::DrawLine(SDL_Surface* screen, int x, int y, int l, int dx, int dy, Uint32 color)
{
	for (int i = 0; i < l; i++) {
		DrawPixel(screen, x, y, color);
		x += dx;
		y += dy;
	};
}

void Draw::DrawRectangle(SDL_Surface* screen, int x, int y, int l, int k, Uint32 OUTlineColor, Uint32 fillColor)
{
	int i;
	DrawLine(screen, x, y, k, 0, 1, OUTlineColor);
	DrawLine(screen, x + l - 1, y, k, 0, 1, OUTlineColor);
	DrawLine(screen, x, y, l, 1, 0, OUTlineColor);
	DrawLine(screen, x, y + k - 1, l, 1, 0, OUTlineColor);
	for (i = y + 1; i < y + k - 1; i++)
		DrawLine(screen, x + 1, i, l - 2, 1, 0, fillColor);
}

Draw::Draw() {

	charset = SDL_LoadBMP("image/cs8x8.bmp");
	if (charset == NULL) {
		printf("SDL_LoadBMP(cs8x8.bmp) error: %s\n", SDL_GetError());
		SDL_Quit();
	};
	SDL_SetColorKey(charset, true, 0x000000);
}

Draw::~Draw()
{
	//SDL_FreeSurface(charset);
}
