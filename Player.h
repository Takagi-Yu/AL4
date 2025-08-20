#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class MapChipField;

class Player {
public:
	// 左右
	enum class LRDirection {
		kRight,
		kLeft,
	};

	// 角
	enum Corner { kRightBottom, kLeftBottom, kRightTop, kLeftTop, kNumCorner };

	/// 初期化
	void Initialize(Model* model, Camera* camera, const Vector3& position);

	/// 更新
	void Update();

	/// 描画
	void Draw();

	// getter
	const WorldTransform& GetWorldTransform() const { return worldTransform_; }

	const Vector3& GetVelocity() const { return velocity_; }

	void SetMapChipField(MapChipField* mapChipField) { mapChipField_ = mapChipField; }

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	Camera* camera_ = nullptr;

	// 移動量
	Vector3 velocity_ = {};
	// フレームごとの加速度
	static inline const float kAcceleration = 0.1f;
	// 非入力時の摩擦係数
	static inline const float kAttenuation = 0.05f;
	// 最高速度
	static inline const float kLimitRunSpeed = 0.3f;
	// 顔の向き
	LRDirection lrDirection_ = LRDirection::kRight;
	// 旋回開始時の角度
	float turnFirstRotationY_ = 0.0f;
	// 旋回タイマー
	float turnTimer_ = 0.0f;
	// 旋回時間<秒>
	static inline const float kTimeTurn = 0.3f;
	// 着地フラグ
	bool onGround_ = true;
	// ジャンプ定数もろもろ
	static inline const float kJumpAcceleration = 20.0f;
	static inline const float kGravityAcceleration = 0.98f;
	static inline const float kLimitFallSpeed = 0.5f;

	// マップチップによるフィールド
	MapChipField* mapChipField_ = nullptr;
	// キャラクターの当たり判定サイズ
	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;
	
	static inline const float kBlank = 0.04f;

	// 移動入力
	void InputMove();
	
	struct CollisionMapInfo {
		bool ceiling = false;
		bool landing = false;
		bool hitWall = false;
		Vector3 move;
	};
	
	void CheckMapCollision(CollisionMapInfo& info);
	
	void CheckMapCollisionUp(CollisionMapInfo& info);
	void CheckMapCollisionDown(CollisionMapInfo& info);
	void CheckMapCollisionRight(CollisionMapInfo& info);
	void CheckMapCollisionLeft(CollisionMapInfo& info);
	
	Vector3 CornerPosition(const Vector3& center, Corner corner);

	// 設置状態の切り替え処理
	void UpdateOnGround(const CollisionMapInfo& info);

	// 壁接触している場合の処理
	void UpdateOnWall(const CollisionMapInfo& info);

	// 着地時の速度減衰率
	static inline const float kAttenuationLanding = 0.0f;
	// 微小な数値
	static inline const float kGroundSearchHeight = 0.06f;
	// 着地時の速度減衰率
	static inline const float kAttenuationWall = 0.2f;
};