# cpp_00_42

## Overview

このリポジトリは、C++プログラミングの基本を学ぶ課題を含んでいます。以下に各課題の概要と設計について説明します。

---

## Assignments

### ex00: Uppercase Converter

#### Description
小文字を大文字に変換するシンプルなプログラムです。

#### Features
1. **基本構成**
   - `Makefile` 作成 ✅
   - テストスクリプト `test.sh` 作成 ✅
   - メインプログラム `main` 作成 ✅

#### Notes
- `argv` の中身を直接変更可能（Cでは不可）。
- 設計は不要、シンプルな処理を実装。

---

### ex01: PhoneBook Application

#### Description
連絡先を管理する簡単なアプリケーション。

#### Features

1. **基本構成**
   - `Makefile` 作成 ✅
   - テストスクリプト `test.sh` 作成 ✅
   - メインプログラム `main` 作成 ✅

2. **クラス設計**
   - **Contactクラス**
      - プライベートメンバ変数として連絡先の詳細情報を管理。作成 ✅
      - 必要に応じて値を出力するメソッドを提供。作成 ✅
         - 登録時のバリデーション
         - 適切な出力を提供
         - シグナルをハンドリングする(Ctrl C, D \)
   
   - **PhoneBookクラス**
      - `Contact` クラスのデフォルト値を初期化。作成 ✅
      - 最大8件の連絡先を管理する。作成 ✅
         - 適切な出力を提供
         - シグナルをハンドリングする(Ctrl C, D \)

3. **ユーザーインターフェース**
   - **登録**: 新しい連絡先を追加。作成 ✅
   - **検索**: 登録済みの連絡先を表示し、詳細を確認可能。作成 ✅
   - **終了**: プログラムを終了。作成 ✅
   - **例外処理**: 不正な入力に対応し、エラーメッセージを表示。作成 ✅

#### Notes
- クラス設計の基本を学ぶ良い機会。
- 動的領域の確保に関して、具体的な処理を整理する必要あり。

---

### ex02: Restore Program

#### Description
プログラムを復元する課題。ヘッダーファイルでのプロトタイプ宣言、
過去のログファイルと対応するテストスクリプトあり
* 要件は逆にない

#### Features
1. **基本構成**
   - `Makefile` 作成 ✅
   - `tests.cpp` 理解 ✅
   - `Account.hpp` 理解 ✅
   - 要件洗い出し ✅
   - 実装 ✅
   - テスト ✅

2. **クラス設計**
   - **Accountクラス**

#### Notes

---

## References

### Documentation
- [CPP Tutorial (cplusplus.com)](https://cplusplus.com/doc/)
- [CPP Reference (cppreference.com)](https://en.cppreference.com/w/)

### Articles
- [クラスの基本 (Qiita)](https://qiita.com/Yuya-Shimizu/items/45d42fe2942a684fa96a)
- [クラスの基本 (Zenn)](https://zenn.dev/k2323/articles/a6b5968445f5a5)

### Article Notes
- [クラス初期化のメモ (Zenn)](https://zenn.dev/melos/articles/7b7fbc5fd41270)

---