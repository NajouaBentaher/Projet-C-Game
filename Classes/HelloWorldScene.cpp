#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

   
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //setting image bg
    auto backgroundSprite = Sprite::create("HelloWorld.png");
    backgroundSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    backgroundSprite->setScale(1.80f);

    auto texture = Director::getInstance()->getTextureCache()->addImage("HelloWorld.png");
    if (backgroundSprite->initWithTexture(texture))
    {
        this->addChild(backgroundSprite);
    }
    //setting image bg
    auto backmysprite = Sprite::create("level1.png");
    backmysprite->setPosition(Vec2(visibleSize.width/2 , visibleSize.height/2 ));
    backmysprite->setScale(1.12f);

    auto texture = Director::getInstance()->getTextureCache()->addImage("level1.png");
    if (backmysprite->initWithTexture(texture))
    {
        this->addChild(backmysprite);
    }
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
 
    mySprite = Sprite::create("Sprite.png");
    this->addChild(mySprite);
    mySprite->setPosition(Vec2(visibleSize.width * 0.06, visibleSize.height * 0.128));

        auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) mutable {
        Vec2 velocity = Vec2(0, 200);
        Vec2 loc = event->getCurrentTarget()->getPosition();

        auto newPosition = loc + Vec2(0, 100);
        auto jumpHeight = 100;
        auto jumpDuration = 0.5f;
        auto jumpAction = MoveTo::create(jumpDuration, loc + Vec2(50, jumpHeight));

        auto downDuration = 0.5f;
        auto downAction = MoveTo::create(downDuration, loc + Vec2(100, 0));
        auto sequence = Sequence::create(jumpAction, downAction, NULL);

        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            event->getCurrentTarget()->setPosition(----------loc.x, loc.y);
            event->getCurrentTarget()->setScaleX(-1);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->setPosition(++++++++++loc.x, loc.y);
            event->getCurrentTarget()->setScaleX(1);

            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
            event->getCurrentTarget()->runAction(sequence);;

            break;

        case EventKeyboard::KeyCode::KEY_SPACE:
            event->getCurrentTarget()->runAction(sequence);;

            break;
        }
    };
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, mySprite);
  return true;
}