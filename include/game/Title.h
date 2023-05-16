#ifndef TITLE_H
#define TITLE_H

class Title {
protected:
    enum class etat {WAIT, START};

private:
    etat m_state;
    const int _FPS=60;
	const int _frameDelay=1000/_FPS;
	unsigned long m_frameStart;
	int m_frameTime;

public:
    Title();

    void run();
};

#endif