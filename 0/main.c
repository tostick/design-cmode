#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 不会实现？？？

// 音乐类型包含mp3\wma\mp4 etc
// 每个类型均对应一系类操作
struct MUSIC_OPS;
typedef struct MUSIC
{
	char type[10];
	struct MUSIC_OPS * ops;
}MUSIC;
struct MUSIC_OPS
{
	void (*read_file)(struct MUSIC* pMusicFile);
	void (*play)(struct MUSIC* pMusicFile);
	void (*stop)(struct MUSIC* pMusicFile);
	void (*back)(struct MUSIC* pMusicFile);
	void (*front)(struct MUSIC* pMusicFile);
	void (*down)(struct MUSIC* pMusicFile);
	void (*up)(struct MUSIC* pMusicFile);
};

void play(struct MUSIC* pMusicFile)
{
//	printf("music file type is %s file\n", pMusicFile.type);
	printf("---\n");
}

int main(int argc, char **argv)
{
	MUSIC music[2];	

	printf("---begin---\n");
	strcpy(music[0].type, "mp3");
	strcpy(music[1].type, "wma");
	
	music[0].ops->play = &play;
	

	return 0;
}
