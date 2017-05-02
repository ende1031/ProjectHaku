#pragma once
#include <irrKlang.h>
#pragma comment(lib, "irrKlang.lib")

class Sound
{
public:
	Sound();
	~Sound();

	void Start();

	void PlayBGM(const char* soundFileName);
	void PlaySE(const char* soundFileName);
	void Stop();
	void Pause();
	void Replay();

private:
	irrklang::ISoundEngine* m_SoundEngine;
};