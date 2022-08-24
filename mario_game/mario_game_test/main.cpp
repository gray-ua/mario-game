#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>

using namespace sf;


float offsetX=0, offsetY=0;


const int H = 20;
const int W = 400;


String TileMap[H] = {
									  //|40                                     |80                 |100                  |122                        |150                                              |200                                              |250                                              |300                                              |350                                              |400
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                                                                                                    BBBBB                                                                            BB                                     BBBBB                                                                                                                   BBBBB                          =          B",
"B0                                     0           0                                                                 BBBBB                                                                          B                                        BBBBB                                                                                                                   BBBBB                          =          B",
"BB        BBBBBBBBBBBB    0                 B                                                                        BBBBB                                                                  r      B                                         BBBBB                                                                                                                   BBBBB                          =          B",
"B                         0                                                                                          BBBBB                                                         R              B                                          BBBBB                                                                                                                   BBBBB                          =          B",
"B  B                      0                       B                                                                  BBBBB                                                                       B                                           BBBBB                                                                                                                   BBBBB                          =          B",
"B      B                  0                                                                                          BBBBB                                 R                                    B                                            BBBBB                                                                                                                   BBBBB                          =          B",
"B        BBBBB                        000   B                                                                        BBBBB              r                                          000000      B     R                                       BBBBB                                                                                                                   BBBBB                          =          B",
"B     r       B                                                                                                      BBBBB                    000000                    r                     B                                              BBBBB                                                                                                                   BBBBB                          =          B",
"B              B      B   r         BBBBBBB     0            R                                                       BBBBB                                                         BBBBBB    B                                               BBBBB                                                                                                                   BBBBB                          =          B",
"B  0                                        BBBBBBB            0             R                       0000000000000   BBBBB                           BBBB                     B                                 r                            BBBBB                                      0         0                                                                  BBBBB                          =          B",
"B  0   BBBBBBBB           BBBBBBBB                                                         r        |            |0  BBBBB               r        B           r B         B       B B  B  B  B     B                 R                       BBBBB                             0   R        0         0         0                                                    BBBBB                          =          B",
"B                        BB            R      0     BBBBBBBB 0      r                           R   BBBBBBBBBBBBBBBBBBBBBB       R             r                B   R                          B                                         r   BBBBB       0               0      R     R  BBBBBBBBBBBBBBBBBBBBBBBBB   B                                               BBBBB                          =          B",
"B   00000000     BBBBBB           B           0                                  R            B                      BBBBB R                B          R        BB        r     B      R      B             r                    R           BBBBB        R                 BBB  0 B                     R               B   0           0          0                BBBBB                          =          B",
"B                  |                       BBBBBBB      0    BB                          B            r              BBBBB            BBBB                      B              B             B       r        0 0 0 0 0 0 0 000              BBBBB             r       B   r     0              r                r        BBBB         R R R R R R R R R             BBBBB                          =          B",
"B              BB                   2                                               B                         C      BBBBB      BBBB                            BBB           B                                                        C     BBBBB                 BB            0                                             B       B              B        C     BBBBB                          =          B",
"B              BB  1  0|       |0   /                           |            | B                                     BBBBB      B0     |              |         B            B             B                 |                |              BBBBB           0000      00000                   0 0  0  0 0                   B                                       BBBBB                          =          B",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBB-BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB_____BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",

};
void game(RenderWindow & window, bool t, int lvl);
void menu(RenderWindow & window);
void level(RenderWindow & window, bool t, int lvl);
void option(RenderWindow & window);
void you_died(RenderWindow & window);

bool flag = true;
bool flag1 = false;
int ahp = 0;
int currlife = 3;

bool you_won = false;

void pers_died(RenderWindow & window, float time);

class PLAYER {

public:

float dx,dy;
FloatRect rect;
bool onGround;
Sprite sprite;
bool life;
int score;
float currentFrame;

    PLAYER(Texture &image, int x, int y)
   {
	sprite.setTexture(image);
	rect = FloatRect(x,y,31,44);
	life = true;
	score = 0;
	dx=dy=0.1;
	currentFrame = 0;
   }


   void update(RenderWindow & window, float time, bool you_won, bool k,int lvl)
   {
	   if(you_won){
	   }
	  
	if(!life){
		dx = dy = 0;
		pers_died(window, time);
		sprite.setPosition(1200,1200);
	}
	else{
	 rect.left += dx * time * 3;
	 score = Collision(0,window,k,lvl,time);

	 if (!onGround) dy=dy+0.0005*time;
	 rect.top += dy*time;
	 onGround=false;
	 score = Collision(1,window,k,lvl,time);
	 
	 if(you_won){
		dx = dy = 0;
	 }
  
	 
	  currentFrame += 0.005*time;
	  if (currentFrame > 4) currentFrame -=4;

	  if (dx>0) sprite.setTextureRect(IntRect(31*int(currentFrame)+31,0,-31,44));
	  if (dx<0) sprite.setTextureRect(IntRect(31*int(currentFrame),0,31,44));
	 

	  sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

	  dx=0;
	}
   }



int Collision(int dir,RenderWindow & window, bool k,int lvl, float time)
   {
     for (int i = rect.top/60 ; i<(rect.top+rect.height)/60; i++)
	  for (int j = rect.left/60; j<(rect.left+rect.width)/60; j++)
		{ 
	  	 if (TileMap[i][j]=='B' || TileMap[i][j]=='1' || TileMap[i][j]=='2' || TileMap[i][j]=='/' || TileMap[i][j]=='=') 
		   { 
	        if ((dx>0) && (dir==0)) rect.left =  j*60 -  rect.width; 
		    if ((dx<0) && (dir==0)) rect.left =  j*60 + 60;
			if ((dy>0) && (dir==1))  { rect.top =   i*60 -  rect.height;  dy=0;   onGround=true; }
			if ((dy<0) && (dir==1))  { rect.top = i*60 + 60;   dy=0;}
		   }
		 
		 if (TileMap[i][j]=='0') 
		    { 
				score++;
			    TileMap[i][j]=' ';
			}
		if (TileMap[i][j]=='_') // когда кол во жизней = 1 и я умираю от ямы фоновая музыка не отключаеться
		    { 
				currlife--;
				flag1 = true;
				if(currlife == 0){
					dx = dy = 0;
					// тут бы музыку отключить
					pers_died(window, time);
				}
				//music.stop();
				game(window, k, lvl);
			}
//		if (TileMap[i][j]=='O') 
//		    { 
//				score++;
//			    TileMap[i][j]='0';
//			} 	
    	}
		return score;
   }
};

class ENEMY
{

public:
float dx,dy;
FloatRect rect;
Sprite sprite;
float currentFrame;
bool life;


   void set(Texture &image, int x, int y)
   {
	sprite.setTexture(image);
	rect = FloatRect(x,y,16,16);

    dx=0.05;
	currentFrame = 0;
	life=true;
   }

   void update(float time)
   {	
	 rect.left += dx * time;
	
     Collision();
  

     currentFrame += time * 0.005;
	 if (currentFrame > 2) currentFrame -= 2;
	 
    sprite.setTextureRect(IntRect(30*int(currentFrame),   4, 16,16));
	
	if (!life) {
		sprite.setTextureRect(IntRect(60, 8, 16,10));
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY + 16);
		sprite.setPosition(1200,1200);
	}
	else{
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	}  
   }


   void Collision()
  {

	for (int i = rect.top/60 ; i<(rect.top+rect.height)/60; i++)
		for (int j = rect.left/60; j<(rect.left+rect.width)/60; j++)
			 if (TileMap[i][j] == '|')
			{ 
                if (dx>0)
				{ rect.left =  j*60 - rect.width; dx*=-1; }
				else if (dx<0)
				{ rect.left =  j*60 + 60;  dx*=-1; }
											
			}
  }

};
class FENEMY
{

public:
float dx,dy;
FloatRect rect;
Sprite sprite;
float currentFrame;


   void set(Texture &image, int x, int y)
   {
	sprite.setTexture(image);
	rect = FloatRect(x,y,24,16);

    dy=-0.05;
	currentFrame = 0;
   }

   void update(float time)
   {	
	 rect.top += dy * time;
	
     Collision();
  

     currentFrame += time * 0.005;
	 if (currentFrame > 2) currentFrame -= 2;
	 
	sprite.setTextureRect(IntRect(30*int(currentFrame)+390, 30, 17,24));
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY + 24);
   }


   void Collision()
  {

	for (int i = rect.top/60 ; i<(rect.top+rect.height)/60; i++)
		for (int j = rect.left/60; j<(rect.left+rect.width)/60; j++)
			 if (TileMap[i][j] == '|' || TileMap[i][j] == '-')
			{ 
                if (dy>0) { rect.top =  i*60 - rect.height; dy*=-1; }
				else if (dy<0) { rect.top =  i*60 + 60;  dy*=-1; }
											
			}
  }

};


Texture setImage(int num);

int main()
{
	RenderWindow window(VideoMode(1024, 512), "MiniMario");
    menu(window);
    return 0;
}


int lvl = 1;

void menu(RenderWindow & window)//функція меню
{
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground;//
	menuTexture1.loadFromFile("images/play.png");
	menuTexture3.loadFromFile("images/exit.png");
	menuBackground.loadFromFile("images/BG.jpg");

	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);

	int f = 1, menuNum = 0;

	menu1.setPosition(365, 67);
	menu3.setPosition(510, 300);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ////////////////////////////////
	while (window.isOpen())//цикл віктритого вікна
	{
		menu1.setColor(Color::White);//заливка кольору в текстуру 
		menu3.setColor(Color::White);

		menuNum = 0;
		
		window.clear(Color::Blue);//ощищення вікна
		
		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
			{
				window.close();
			}
		}
		if (IntRect(416, 100, 192, 96).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Green); menuNum = 1; }
		if (IntRect(419, 300, 188, 94).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Green); menuNum = 2; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { window.clear();
				bool t = true; 
				level(window, t, lvl); };//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.close(); }

		}
		window.draw(menuBg);//вивід спарйтів на екран 
		window.draw(menu1);
		window.draw(menu3);
		window.display();
	}
	////
}

void option(RenderWindow & window){
	Image h;
    h.loadFromFile("images/Cloud1.png");
	Texture t;
	t.loadFromImage(h);
	Sprite s;
	s.setPosition(10,10);

	

	while (window.isOpen()){
		window.clear(Color::White);
		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
			{
				window.close();
			}
		}
	}

	window.draw(s);
	window.display();

}




void pers_died(RenderWindow & window, float time){
	SoundBuffer buffer1;
	buffer1.loadFromFile("music/you_died.ogg");
	Sound you_died_sound(buffer1);

	Texture you_died;
	you_died.loadFromFile("images/you_died_sprite.png");
	Sprite yds;
	yds.setTexture(you_died);

	const int died = 1;
	int fdied = 1;
	float currentFrame=0;
	while (window.isOpen()){
		
		window.clear();

		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::BackSpace))
			{
				you_died_sound.stop();
			  //window.clear();
			  level(window, false, lvl);
			}
		}

		currentFrame += 0.00015*time;
		if (currentFrame > 5) currentFrame -=5;
		yds.setTextureRect(IntRect(1024*int(currentFrame),0,1024,512));
		while(fdied){
			you_died_sound.play();
			fdied = died - fdied;
		}
		you_died_sound.setLoop(true);
		window.draw(yds);
		window.display();
	}
}





void game(RenderWindow & window, bool k, int lvl){

	offsetX = 0;
	offsetY = 0;

	int counthp = 0;

	Image him;
    him.loadFromFile("images/hero.png");
    him.createMaskFromColor(Color::White);
	Texture t;
	t.loadFromImage(him);

	Texture et;
	et.loadFromFile("images/enemies.png");

	Texture c;
	c.loadFromFile("images/castle.png");
	Sprite cs;
	cs.setTexture(c);

	Texture you_died;
	you_died.loadFromFile("images/you_died_sprite.png");
	Sprite yds;
	yds.setTexture(you_died);

	Texture cl1;
	cl1.loadFromFile("images/cloud2.png"); // R
	Sprite cl1s;
	cl1s.setTexture(cl1);

	Texture cl2;
	cl2.loadFromFile("images/cloud1.png"); // r
	Sprite cl2s;
	cl2s.setTexture(cl2);

	Texture t1;
	t1.loadFromFile("images/truba1.png");
	Sprite t1s;
	t1s.setTexture(t1);

	Texture t2;
	t2.loadFromFile("images/truba2.png");
	Sprite t2s;
	t2s.setTexture(t2);

	Texture tcoin;
	tcoin.loadFromFile("images/coin_sprite.png");
	Sprite tcoins;
	tcoins.setTexture(tcoin);

    Image mim;
    mim.loadFromFile("images/blocks.png");
    Texture te;
    te.loadFromImage(mim);
    Sprite s_bl;
	s_bl.setTexture(te);

	SoundBuffer buffer1;
	buffer1.loadFromFile("music/you_died.ogg");
	Sound you_died_sound(buffer1);

//	Movie movie;
	
//		if (!movie.OpenFromFile("movie.avi"))
//			return 1;
	
//		movie.ResizeToFrame(0, 0, 640, 480);
//		movie.Play();
	
	
	SoundBuffer buffer;
	buffer.loadFromFile("music/Jump.ogg");
	Sound sound(buffer);

    Music music;
    music.openFromFile("music/Mario_Theme.ogg");
	music.play();
	
	k = false;
	
	float currentFrame=0;
	float currCoinFrame = 0;
	
		PLAYER p(t,2*60*((lvl-1)*60+1),14*60);

		ENEMY  enemy;
		ENEMY  enemy11;
		ENEMY  enemy12;
		ENEMY  enemy21;
		ENEMY  enemy22;

		FENEMY fenemy;

		enemy.set(et,30*60,16*60 + 27);
		enemy11.set(et,67*60,16*60 + 11);
		enemy12.set(et,102*60,11*60 + 27);
		enemy22.set(et,207*60,16*60 + 27);
		enemy21.set(et,141*60,16*60 + 27);
		fenemy.set(et,19*60 + 12,17*60);
		enemy.sprite.setScale(2,2);
		enemy12.sprite.setScale(2,2);
		enemy22.sprite.setScale(2,2);
		enemy11.sprite.setScale(3,3);
		enemy21.sprite.setScale(2,2);
		fenemy.sprite.setScale(2,2);
		cs.setScale(2,2);
	
		Clock clock;
		Clock cgameTime;
		int gameTime = 0;
	
		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			if(p.life) gameTime = cgameTime.getElapsedTime().asSeconds();
			clock.restart();
			
	
			time = time/500;
			
			if (time>20) time = 20;
			if (p.rect.left>300) offsetX = p.rect.left - 300; 
			offsetY = p.rect.top - 300;
	
			window.clear(Color(50, 70, 255));

			sf::Font font;
			if (!font.loadFromFile("fonts/SpikeyBit.ttf"))
			{
				std::cout << "can`t open file 'fonts/SpikeyBit.ttf' " << std::endl;
			}
			Text text_timer,text_score, text_lives, text_won;
			// select the font
			text_timer.setFont(font);
			text_score.setFont(font);
			text_lives.setFont(font);
			text_won.setFont(font);
			// set the string to display
			
			// set the character size
			text_timer.setCharacterSize(24);
			text_score.setCharacterSize(24); // in pixels, not points!
			text_lives.setCharacterSize(24);
			text_won.setCharacterSize(24);
			// set the color
			text_timer.setColor(Color::White);
			text_score.setColor(Color::White);
			text_score.setPosition(13*60,0);
			text_lives.setColor(Color::White);
			text_won.setColor(Color::White);
			text_lives.setPosition(13*60,60);
			text_won.setPosition(416,250);
			

			Event event;
			while (window.pollEvent(event))
			{
				if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
				{
				  window.close();
				}
				if (Keyboard::isKeyPressed(Keyboard::BackSpace))
				{
				  //window.clear();
				  music.stop();
				  level(window, k, lvl);
				}
			}
	
			if (Keyboard::isKeyPressed(Keyboard::Left) && !you_won) 
			{
				p.dx = -0.1;
	
			}
	
			if (Keyboard::isKeyPressed(Keyboard::Right) && !you_won) 
			{
				p.dx = 0.1;
			}
	
			if (Keyboard::isKeyPressed(Keyboard::Up) && !you_won) 
			{
				if (p.onGround) { p.dy=-0.4; p.onGround=false; sound.play();}
			}
			p.update(window, time, you_won, k, lvl);
			enemy.update(time);
			enemy11.update(time);
			enemy22.update(time);
			enemy12.update(time);
			enemy21.update(time);
			fenemy.update(time);
			text_won.setString("YOU WON!!!");
			 if  (p.rect.intersects( enemy.rect )  )
			 {
			 	if (enemy.life) {
			 		if (p.dy>0) { enemy.dx=0; p.dy=-0.2; enemy.life=false; p.score += 100;}
					else{
						if(currlife > 1){
							music.stop();
							currlife--;
							game(window, k, lvl);
						}
						else{
							p.life = false;
						}
						music.stop();
					}
				}
				 
			}
			if(p.rect.intersects(enemy11.rect)){
				if (enemy11.life) {
					if (p.dy>0) { enemy11.dx=0; p.dy=-0.2; enemy11.life=false; p.score += 1000;}
				   else {
					if(currlife > 1){
						music.stop();
						currlife--;
						game(window, k, lvl);
					}
					else{
						p.life = false;
					}
					music.stop();
				   }
			   }
			}
			if(p.rect.intersects(enemy12.rect)){
				if (enemy12.life) {
					if (p.dy>0) { enemy12.dx=0; p.dy=-0.2; enemy12.life=false; p.score += 100;}
				   else {
					if(currlife > 1){
						music.stop();
						currlife--;
						game(window, k, lvl);
					}
					else{
						p.life = false;
					}
					music.stop();
				   }
			   }
			}
			if(p.rect.intersects(enemy22.rect)){
				if (enemy22.life) {
					if (p.dy>0) { enemy22.dx=0; p.dy=-0.2; enemy22.life=false; p.score += 100;}
				   else {
					if(currlife > 1){
						music.stop();
						currlife--;
						game(window, k, lvl);
					}
					else{
						p.life = false;
					}
					music.stop();
				   }
			   }
			}
			if(p.rect.intersects(enemy21.rect)){
				if (enemy21.life) {
					if (p.dy>0) { enemy21.dx=0; p.dy=-0.2; enemy21.life=false; p.score += 100;}
				   else {
					if(currlife > 1){
						music.stop();
						currlife--;
						game(window, k, lvl);
					}
					else{
						p.life = false;
					}
					music.stop();
				   }
			   }
			}
			if  (p.rect.intersects( fenemy.rect ) )
			{
				if(currlife > 1){
					music.stop();
					currlife--;
					game(window, k, lvl);
				}
				else{
					p.life = false;
				}
				music.stop();
		   }
		   if  (p.rect.contains( 112*60-10,16*60+30 ) )
		   {
				 lvl++;
				 music.stop();
				 game(window, k, lvl);
		  }
		  if  (p.rect.contains( 232*60-10,16*60+30 ) )
		  {
				lvl++;
				music.stop();
				game(window, k, lvl);
		 }
		 
		 if  (p.rect.contains( 353*60-10,16*60+30 ) )
		 {
			   music.stop();
			   you_won = true;
		}
		if(flag1){// когда кол во жизней = 1 и я умираю от ямы фоновая музыка не отключаеться
			music.stop();
		}
			window.draw(fenemy.sprite);
			 for (int i=0; i<H; i++)
				 for (int j=0; j<W ; j++)
					{ 
					  if (TileMap[i][j]=='B') s_bl.setTextureRect(IntRect(0,0,60,60));
	
					  if (TileMap[i][j]=='0') { 

							currCoinFrame += 0.000025*time;
							if(currCoinFrame > 2) currCoinFrame -= 2;
							if((int)currCoinFrame == 0) tcoins.setTextureRect(IntRect(0,0,60,60));
							if((int)currCoinFrame == 1) tcoins.setTextureRect(IntRect(60,0,60,60));
							tcoins.setPosition(j*60-offsetX,i*60 - offsetY);
							window.draw(tcoins);
							continue;
						}
					  //if (TileMap[i][j]=='O') { s_bl.setTextureRect(IntRect(60,0,60,60)); }

					  if (TileMap[i][j]=='C'){ cs.setPosition(j*60-offsetX,i*60 - offsetY-87); window.draw(cs); continue;}

					  if(TileMap[i][j]=='1'){ t1s.setPosition(j*60-offsetX,i*60 - offsetY); continue;}

					  if(TileMap[i][j]=='2'){ t2s.setPosition(j*60-offsetX,i*60 - offsetY); continue;}

					  if(TileMap[i][j]=='R'){ cl1s.setPosition(j*60-offsetX,i*60 - offsetY); window.draw(cl1s); continue;}

					  if(TileMap[i][j]=='r'){ cl2s.setPosition(j*60-offsetX,i*60 - offsetY); window.draw(cl2s); continue;}
	
					  if (TileMap[i][j]==' ' || TileMap[i][j]=='|' || TileMap[i][j]=='/' || TileMap[i][j]=='=' || TileMap[i][j]=='_') continue;
	
					  s_bl.setPosition(j*60-offsetX,i*60 - offsetY);
					  
					  window.draw(s_bl);
					}
					std::ostringstream gameTimeString, gameScoreString, gameLivesString;
					gameTimeString << gameTime;
					gameScoreString << p.score;
					gameLivesString << currlife;
			music.setLoop(true);
			window.draw(p.sprite);
			window.draw(enemy.sprite);
			window.draw(enemy11.sprite);
			window.draw(enemy22.sprite);
			window.draw(enemy12.sprite);
			window.draw(enemy21.sprite);
			text_timer.setString("Timer: " + gameTimeString.str());
			text_score.setString("Score: " + gameScoreString.str());
			text_lives.setString("Lives: " + gameLivesString.str());
			window.draw(text_timer);
			window.draw(text_score);
			window.draw(text_lives);
			if(you_won){
				window.draw(text_won);
			}
			window.draw(t1s);
			window.draw(t2s);
			window.display();

		}
}

void you_died(RenderWindow & window){
	Texture you_died;
	you_died.loadFromFile("images/you_died.gif");
	Sprite yd;
	yd.setTexture(you_died);

	while (window.isOpen()){
		window.clear();
		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
			  //window.clear();
			  level(window, true, lvl);
			}
		}
	}

	window.draw(yd);
	window.display();
}

const int L_H = 5;
const int L_W = 12;

// String LevelMap[L_H] = {
// 	"        0   ",//40
// 	"            ",
// 	"            ",
// 	"   0        ",
// 	" 0  0  0  0 "
// };

void level(RenderWindow & window, bool k, int lvl)
{
	Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12;
	Sprite s_l1,s_l2,s_l3,s_l4,s_l5,s_l6,s_l7,s_l8,s_l9,s_l10,s_l11,s_l12;

		t1.loadFromFile("images/numb/1.png");
		s_l1.setTexture(t1);

		t2.loadFromFile("images/numb/2.png");
		s_l2.setTexture(t2);

		t3.loadFromFile("images/numb/3.png");
		s_l3.setTexture(t3);
	Texture lbg;
	lbg.loadFromFile("images/ground.png");
	Sprite slbg;
	slbg.setTexture(lbg);
	slbg.setPosition(0,0);

	int lvlNum = 1;

	while (window.isOpen())
	{
		window.clear();
		window.draw(slbg);

	for (int i=0; i<L_H; i++)
	for (int j=0; j<L_W ; j++)
	   {

		 if(lvlNum == 1)  s_l1.setPosition(3*50, 5*50);
		 if(lvlNum == 2)  s_l2.setPosition(3*50, 2*50 + 10);
		 if(lvlNum == 3)  s_l3.setPosition(7*50, 2*50 + 10);
		 if(lvlNum == 4)  s_l4.setPosition(j*50, i*50);
		 if(lvlNum == 5)  s_l5.setPosition(j*50, i*50);
		 if(lvlNum == 6)  s_l6.setPosition(j*50, i*50);
		 if(lvlNum == 7)  s_l7.setPosition(j*50, i*50);
		 if(lvlNum == 8)  s_l8.setPosition(j*50, i*50);
		 if(lvlNum == 9)  s_l9.setPosition(j*50, i*50);
		 if(lvlNum == 10) s_l10.setPosition(j*50, i*50);
		 if(lvlNum == 11) s_l11.setPosition(j*50, i*50);
		 if(lvlNum == 12) s_l12.setPosition(j*50, i*50);
		 window.draw(s_l1);window.draw(s_l2);window.draw(s_l3);window.draw(s_l4);window.draw(s_l5);window.draw(s_l6);
		 window.draw(s_l7);window.draw(s_l8);window.draw(s_l9);window.draw(s_l10);window.draw(s_l11);window.draw(s_l12);
		 lvlNum++;
	   }

	   

	   Event event;
	   while (window.pollEvent(event))
	   {
		   if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
		   {
			   window.close();
		   }
		   if (k && Keyboard::isKeyPressed(Keyboard::BackSpace))
		   {
			 window.clear();
			 menu(window);
		   }
	   }
	   k = true;
		if (IntRect(3*50, 5*50, 50, 50).contains(Mouse::getPosition(window)) && lvl >= 1) { 
			lvlNum = 1;
		}
		if (IntRect(3*50, 2*50 + 10, 50, 50).contains(Mouse::getPosition(window)) && lvl >= 2) { 
			lvlNum = 2;
		}
		if (IntRect(7*50, 2*50 + 10, 50, 50).contains(Mouse::getPosition(window)) && lvl >= 3) { 
			lvlNum = 3;
		}
		if(Mouse::isButtonPressed(Mouse::Left)){
			if(lvlNum == 1){
				window.clear();
				game(window, k,lvlNum);
			}
			if(lvlNum == 2){
				window.clear();
				game(window, k,lvlNum);
			}
			if(lvlNum == 3){
				window.clear();
				game(window, k,lvlNum);
			}

		}
	
	window.display();

	}

}