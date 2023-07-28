#pragma once

#include <vector>
#include "glm/glm.hpp"

#include "../engine/renderer/texture.h"
#include "../engine/renderer/sprite-renderer.h"

class Player;

class Ghost 
{
public:
    static void reserve_ghosts(size_t num) { ghosts.reserve(num); };
	static bool make(glm::vec2 pos, float hp);
    static void update_all(Player* player1, Player* player2, float dt);
    static void draw_all(SpriteRenderer& renderer);
    static std::vector<Ghost>& get_ghosts() { return ghosts; };
    static bool deactivate(int id);

    glm::vec2 get_pos() { return this->pos; };

    float speed = 3.0f;
    float hp = 5.0f;
    bool is_sucked = false;

private:
    Ghost(glm::vec2 pos, float hp, int id);

    static std::vector<Ghost> ghosts;

    int id;
    bool is_active = true;

    glm::vec2 pos = {};
    float time = 0.0f;
    bool move_right;

    void update(Player& player1, Player& player2, float dt);
    void draw(SpriteRenderer& renderer) const;
};