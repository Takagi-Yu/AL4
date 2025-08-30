#pragma once

#include "KamataEngine.h"
#include "Math.h"
#include "Player.h"

using namespace KamataEngine;

// class Player;
class GameScene;

class Enemy {

public:
	// 振るまい
	enum class Behavior {
		kUnknown = -1, // 無効な状態
		kWalk,         // 歩行状態
		kDefeated,     // やられ状態
	};

	// 初期化
	void Initialize(Model* model, Camera* camera, const Vector3& position);
	// 更新
	void Update();
	// 描画
	void Draw();
	// 02_10 スライド14枚目
	AABB GetAABB();
	// ワールド座標を取得
	Vector3 GetWorldPosition();
	// 衝突応答
	void OnCollision(const Player* player);
	// 02_15 6枚目
	bool IsDead() const { return isDead_; }
	// 02_15 20枚目
	bool IsCollisionDisabled() const { return isCollisionDisabled_; }
	// 02_16 19
	void SetGameScene(GameScene* gameScene) { gameScene_ = gameScene; }

private:
	// ワールド
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// カメラ
	Camera* camera_ = nullptr;

	// 歩くスピード
	static inline const float kWalkSpeed = 0.02f;
	// 速度
	Vector3 velocity_ = {};

	// 最初の角度
	static inline const float kWalkMotionAngleStart = 0.0f;
	// 最後の角度
	static inline const float kWalkMotionAngleEnd = 30.0f;
	// アニメーション時間
	static inline const float kWalkMotionTime = 1.0f;
	// 経過時間
	float walkTimer = 0.0f;

	// 当たり判定サイズ
	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;

	// デスフラグ
	bool isDead_ = false;

	// 02_15 13枚目
	Behavior behavior_ = Behavior::kWalk;
	Behavior behaviorRequest_ = Behavior::kUnknown;

	// 02_15 15枚目
	static inline const float kDefeatedTime = 0.6f;
	static inline const float kDefeatedMotionAngleStart = 0.0f;
	static inline const float kDefeatedMotionAngleEnd = -60.0f;
	float counter_ = 0.0f; // カウンター

	// 02_15 20枚目
	bool isCollisionDisabled_ = false;

	// 02_16 19
	GameScene* gameScene_ = nullptr;

	float turnFirstRotationY_ = 0.0f;
};
