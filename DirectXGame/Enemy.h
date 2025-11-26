#pragma once
#include "KamataEngine.h"
#include "Math.h"
#include "Player.h"

using namespace KamataEngine;

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
	
	AABB GetAABB();
	// ワールド座標を取得
	Vector3 GetWorldPosition();
	// 衝突応答
	void OnCollision(const Player* player);
	
	bool IsDead() const { return isDead_; }
	
	bool IsCollisionDisabled() const { return isCollisionDisabled_; }
	
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

	static inline const float kDefeatedTime = 0.6f;
	static inline const float kDefeatedMotionAngleStart = 0.0f;
	static inline const float kDefeatedMotionAngleEnd = -60.0f;
	float counter_ = 0.0f; // カウンター

	bool isCollisionDisabled_ = false;

	GameScene* gameScene_ = nullptr;

	float turnFirstRotationY_ = 0.0f;
};
