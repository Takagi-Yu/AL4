#pragma once
#include "CameraController.h"
#include "DeathParticles.h"
#include "Enemy.h"
#include "Fade.h"
#include "HitEffect.h"
#include "KamataEngine.h"
#include "MapChipField.h"
#include "Player.h"
#include "skydome.h"
#include <vector>

using namespace KamataEngine;

// ゲームシーンクラス
class GameScene {
public:
	~GameScene();
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	void GenerateBlocks();

	// 衝突判定と応答
	void CheckAllCollisions();

	// デスフラグのgetter
	bool IsFinished() const { return finished_; }

	// エフェクトを生成
	void CreateEffect(const Vector3& position);

	int isPose_ = false;

	int nextScene_ = 0;

private:
	// ゲームのフェーズ（型）
	enum class Phase {
		kFadeIn,  // フェードイン 
		kPlay,    // ゲームプレイ
		kDeath,   // デス演出
		kFadeOut, // フェードアウト 
	};

	// ゲームの現在フェーズ（変数）
	Phase phase_;

	void ChangePhase();

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// スプライト
	Sprite* sprite_ = nullptr;
	// 3Dモデル
	Model* model_ = nullptr;
	// ワールドトランスフォーム
	WorldTransform worldTransform_;
	// カメラ
	Camera camera_;
	// サウンドデータハンドル
	uint32_t soundDataHandle_ = 0;
	// 音声再生ハンドル
	uint32_t voiceHandle_ = 0;

	//  プレイヤー
	Player* player_ = nullptr;
	// プレイヤーモデル
	Model* player_model_ = nullptr;

	// ブロックモデル
	Model* block_model_ = nullptr;
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;
	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

	// 天球
	skydome* skydome_ = nullptr;
	Model* modelSkydome_ = nullptr;

	// マップチップフィールド
	MapChipField* mapChipField_;

	// カメラ移動
	CameraController* CController_ = nullptr;

	Model* enemy_model_ = nullptr;

	std::list<Enemy*> enemies_;

	DeathParticles* deathParticles_ = nullptr;

	Model* deathParticle_model_ = nullptr;

	bool finished_ = false;

	Fade* fade_ = nullptr;

	//Model* Attack_model_ = nullptr;

	std::list<HitEffect*> hitEffects_;

	Model* particle_model_ = nullptr;

	WorldTransform worldTransformTitle_;
	Model* modelTitle_;
	float kTitleFontScale_ = 0.0f;
	WorldTransform worldTransformPose_;
	Model* modelPose_;
	float kPoseFontScale_ = 0.0f;

};