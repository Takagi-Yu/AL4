#include "GameScene.h"
#include "KamataEngine.h"
#include "TitleScene.h"
#include <Windows.h>
using namespace KamataEngine;

TitleScene* titleScene = nullptr;
GameScene* gameScene = nullptr;

enum class Scene {
	kUnknown = 0,
	kTitle,
	kGame,
};
// 現在シーン（型）
Scene scene = Scene::kUnknown;

void ChangeScene() {

	switch (scene) {
	case Scene::kTitle:
		if (titleScene->IsFinished()) {
			// シーン変更
			scene = Scene::kGame;
			delete titleScene;
			titleScene = nullptr;
			gameScene = new GameScene;
			gameScene->Initialize();
		}
		break;
	case Scene::kGame:
		if (gameScene->IsFinished()) {
			if (gameScene->isPose_) {
				if (gameScene->nextScene_ == 0) {
					// シーン変更
					scene = Scene::kTitle;
					// 旧シーンの解放
					//delete gameScene;
					gameScene = nullptr;
					// 新シーンの生成と初期化
					titleScene = new TitleScene;
					titleScene->Initialize();
				}
			} else {
			// シーン変更
			scene = Scene::kTitle;
			delete gameScene;
			gameScene = nullptr;
			titleScene = new TitleScene;
			titleScene->Initialize();
			}
		}
		break;
	}
}

void UpdateScene() {

	switch (scene) {
	case Scene::kTitle:
		titleScene->Update();
		break;
	case Scene::kGame:
		gameScene->Update();
		break;
	}
}

void DrawScene() {
	switch (scene) {
	case Scene::kTitle:
		titleScene->Draw();
		break;
	case Scene::kGame:
		gameScene->Draw();
		break;
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// エンジンの初期化
	KamataEngine::Initialize(L"LE2C_18_タカギ_ユウ_奥へ奥へ");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ImGuiManagerインスタンスの取得
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();

	scene = Scene::kTitle;
	titleScene = new TitleScene;
	titleScene->Initialize();

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// ImGui受付開始
		imguiManager->Begin();

		// シーン切り替え
		ChangeScene();
		// シーン更新
		UpdateScene();

		// ImGui受付終了
		imguiManager->End();

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画
		// titleScene->Draw();

		// シーンの描画
		DrawScene();

		// 軸表示の描画
		AxisIndicator::GetInstance()->Draw();

		// プリミティブ描画のリセット
		PrimitiveDrawer::GetInstance()->Reset();

		// ImGui描画
		imguiManager->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// 各種解放
	delete titleScene;
	//delete gameScene;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}

