#include <player/player_fire_boy.h>

PlayerFireBoy::PlayerFireBoy()
{
    init();
    add_animation("fire_head_idle");
    add_animation("fire_legs_idle");
}

void PlayerFireBoy::init()
{
	load_animation("death_smoke",{0,0});
    load_animation("fire_glow", { 0,0 });
    load_animation("fire_head_falling", { 0,0 });
    load_animation("fire_head_idle", { 0,0 });
    load_animation("fire_head_jumping", { 0,0 });
    load_animation("fire_head_rising", { 0,0 });
    load_animation("fire_ice_legs", { 0,0 });
    load_animation("fire_legs_idle", { 0,0 });
    load_animation("fire_legs_running", { 0,0 });
    load_animation("fire_stairs", { 0,0 });

}