#include "ResourcesSounds.h"

//Singlton
ResourcesSounds::ResourcesSounds()
{
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;

	soundBuffer.loadFromFile("BackGroundMusic.ogg");
	v_soundBuffer.push_back(soundBuffer);
	soundBuffer.loadFromFile("FinishLevel.ogg");
	v_soundBuffer.push_back(soundBuffer);
	soundBuffer.loadFromFile("Click.ogg");
	v_soundBuffer.push_back(soundBuffer);
	

	for (int i = 0; i < NUM_OF_SOUNDS ; i++)
	{
		sound.setBuffer(v_soundBuffer[i]);
		v_sound.push_back(sound);
	}
}
//-----------------------------------------------------------------------------
ResourcesSounds& ResourcesSounds::getInstance()
{
	static ResourcesSounds sound;
	return sound;
}
//-----------------------------------------------------------------------------
void ResourcesSounds::playSound(int index)
{
	v_sound[index].play();
}
//-----------------------------------------------------------------------------
void ResourcesSounds::pauseSound(int index)
{
	v_sound[index].pause();
}
//-----------------------------------------------------------------------------
void ResourcesSounds::playLoop(int index)
{
	v_sound[index].play();
	v_sound[index].setVolume(10);

	v_sound[index].setLoop(true);
}
