# Visual Studio에서의 CPP 프로젝트 구조입니다.

## 프로젝트 구조
- `src/`: 소스 코드 파일들이 위치하는 폴더
- `include/`: 헤더 파일들이 위치하는 폴더
- `lib/`: 외부 라이브러리 파일들이 위치하는 폴더
- `build/`: 빌드 결과물이 생성되는 폴더
- `test/`: 단위 테스트 코드가 위치하는 폴더

## 개발 환경
- Visual Studio 2019 이상
- C++17 이상
- Windows SDK 10.0

## 프로젝트 설정
1. 솔루션 구성
   - Debug/Release 구성 포함
   - x86/x64 플랫폼 지원
   - 속성/모든구성/구성속성
   - 출력 디렉터리: ..\Build\\$(Platform)$(Configuration)\\
   - 중간 디렉터리: ..\Output\\$(Platform)$(Configuration)\\$(ProjectName)\\
2. 주요 컴파일러 설정
   - 문자 집합: 유니코드
   - C++ 언어 표준: C++17
   - 런타임 라이브러리: 멀티스레드 (/MT)

3. 추가 종속성
   - Windows SDK
   - DirectX SDK (필요한 경우)

## 시작하기
1. 저장소 클론
2. Visual Studio에서 솔루션 파일(.sln) 열기
3. 빌드 구성 선택 (Debug/Release)
4. 빌드 및 실행

## 주의사항
- 프로젝트 속성은 모든 구성에 대해 일관되게 설정되어 있음
- 외부 라이브러리 사용 시 lib/ 폴더에 추가 필요
- 빌드 결과물은 자동으로 build/ 폴더에 생성됨
