#pragma once
#include <player/player_base.h>

/**
* @class PlayerFireBoy
* @brief 火孩角色类
**/
class PlayerFireBoy : public PlayerBase
{
public:
	/**
	* @brief 构造函数
	**/
	PlayerFireBoy();
    /**
	* @brief 初始化
	**/
	virtual void init()override;
};