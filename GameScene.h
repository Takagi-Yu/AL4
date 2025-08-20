#pragma once
#include "CameraController.h"
#include "Enemy.h"
#include "KamataEngine.h"
#include "MapChipField.h"
#include "Player.h"
#include "skydome.h"
#include <vector>

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

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	// 3Dモデル
	KamataEngine::Model* model_ = nullptr;
	// ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;
	// カメラ
	KamataEngine::Camera camera_;
	// サウンドデータハンドル
	uint32_t soundDataHandle_ = 0;
	// 音声再生ハンドル
	uint32_t voiceHandle_ = 0;

	//  自キャラ
	Player* player_ = nullptr;
	// プレイヤーモデル
	KamataEngine::Model* player_model_ = nullptr;

	// ブロックモデル
	KamataEngine::Model* block_model_ = nullptr;
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	// デバッグカメラ有効
	bool isDebugCameraActive_ = false;
	// デバッグカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	// 天球
	skydome* skydome_ = nullptr;
	Model* modelSkydome_ = nullptr;
	// WorldTransfrom worldTransformSkydome_;

	// マップチップフィールド
	MapChipField* mapChipField_;

	// カメラ移動
	CameraController* CController_ = nullptr;

	// 敵クラス
	Enemy* enemy_ = nullptr;
	// 敵モデル
	KamataEngine::Model* enemy_model_ = nullptr;
};