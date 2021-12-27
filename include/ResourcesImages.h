#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

//Singleton 
class ResourcesImages
{
public:
	~ResourcesImages() = default;
	static ResourcesImages& getInstance();
	sf::Texture& getTexture(int index);

	enum vectorIconType {
		i_empty_pipe1,
		i_empty_pipe2,
		i_empty_pipe3,
		i_tap,
		i_full_pipe1,
		i_full_pipe2,
		i_full_pipe3,
		i_full_tap,
		i_empty_sink,
		i_full_sink,
		i_startManu,
		i_background1,
		i_empty,
		i_levelCompleted,
		i_gameFinish
	};

private:
	ResourcesImages();
	ResourcesImages(const ResourcesImages&) = default;
	ResourcesImages& operator=(const ResourcesImages&) = default;
	std::vector< sf::Texture > v_texture;
};
