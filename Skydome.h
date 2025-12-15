#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class skydome {
public:
	// 初期化
	void Initialize(Model* model, Camera*);

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	Camera* camera_ = nullptr;
};