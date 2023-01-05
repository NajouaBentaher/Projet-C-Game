#ifndef _HELLOWORLD_SCENE_H_
#define _HELLOWORLD_SCENE_H_

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    cocos2d::Sprite* mySprite;
    void play(Ref* pSender);
    void Highscores(Ref* pSender);
    void Settings(Ref* pSender);
};

#endif // _HELLOWORLD_SCENE_H_