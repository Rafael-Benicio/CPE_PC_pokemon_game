#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>

#include "./../Vector2D.hpp"
#include "./../interfaces/game_object.hpp"


class Player : public GameObject {
    public:
    double speed;
    double speedModifier;
    bool movimentIsBlocked = false;
    bool keyIsPressed      = true;

    Vector2D movimentVector;
    Vector2D movimentTargetPosition;

    enum IMAGE_CHAR { DOWN = 0, LEFT = 1, RIGHT = 2, UP = 3 };
    int frame_x      = 0;
    int frameCounter = 0;

    SDL_Rect mainSquare;
    SDL_Rect imageSquare;

    Player();

    virtual void update();
    virtual void render(SDL_Renderer* window,
    std::map<std::pmr::string, SDL_Texture*>& texture);
    virtual void control(SDL_Event event);

    private:
    void setMainsSquarePosition(Vector2D* vec);
    void setPlayerTargetPosition(int x, int y);

    void keydownMapping(SDL_Event event);
    void keyupMappaing(SDL_Event event);

    void walkingAnimationUpdate();
    void walkingMovimentUpdate();
    void setMovimentRoutine(int x, int y, int imageChar);
    void reachPositionTarget();
};

#endif