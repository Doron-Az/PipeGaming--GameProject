#include "ResourcesImages.h"

//Singlton
ResourcesImages::ResourcesImages()
{
	sf::Texture texture;
	texture.loadFromFile("empty_pipe1.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("empty_pipe2.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("empty_pipe3.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("empty_tap.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("full_pipe1.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("full_pipe2.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("full_pipe3.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("full_tap.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("empty_sink.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("full_sink.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("startManu.png");
	v_texture.push_back(texture);
	texture.loadFromFile("background1.JPG");
	v_texture.push_back(texture);
	texture.loadFromFile("blueRect.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("levelCompleted.PNG");
	v_texture.push_back(texture);
	texture.loadFromFile("gameFinish.PNG");
	v_texture.push_back(texture);

}
//-----------------------------------------------------------------------------
ResourcesImages& ResourcesImages::getInstance()
{
	static ResourcesImages img;
	return img;
}
//-----------------------------------------------------------------------------
sf::Texture& ResourcesImages::getTexture(int index)
{
	return v_texture[index];
}
