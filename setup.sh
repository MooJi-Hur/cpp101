#!/bin/bash

# 소스 및 헤더 디렉토리 생성
for i in {1..20} # 1부터 20까지 반복하는 루프를 생성

do
    # 현재 루프의 숫자에 해당하는 강의명을 할당하기 위해 case 문 사용
    case $i in
        1) lecture_name="comparison" ;;         # 1강: C언어와 C++ 비교하기
        2) lecture_name="classes" ;;            # 2강: C++ 클래스
        3) lecture_name="constructors" ;;       # 3강: 생성자와 소멸자
        4) lecture_name="inheritance" ;;        # 4강: 클래스 상속
        5) lecture_name="overloading" ;;        # 5강: 오버로딩
        6) lecture_name="encapsulation" ;;      # 6강: 캡슐화 기법
        7) lecture_name="polymorphism" ;;       # 7강: 다형성 기법
        8) lecture_name="templates" ;;          # 8강: 템플릿
        9) lecture_name="smart_pointers" ;;     # 9강: 스마트 포인터
        10) lecture_name="stl_container_adapters" ;; # 10강: STL 컨테이너 어댑터
        11) lecture_name="stl_sequence_containers" ;; # 11강: STL 시퀀스 컨테이너
        12) lecture_name="stl_associative_containers" ;; # 12강: STL 연관 컨테이너
        13) lecture_name="exception_handling" ;; # 13강: 예외처리
        14) lecture_name="socket_overview" ;;    # 14강: 소켓프로그래밍 개요
        15) lecture_name="socket_functions" ;;   # 15강: 소켓 함수와 Winsock2
        16) lecture_name="tcp_echo" ;;           # 16강: TCP 에코 통신
        17) lecture_name="github_integration" ;; # 17강: GitHub 연동
        18) lecture_name="boost_asio_overview" ;; # 18강: Boost.Asio 개요 및 설치
        19) lecture_name="boost_asio_basic" ;;   # 19강: Boost.Asio 기본적인 사용법
        20) lecture_name="boost_asio_sync_tcp" ;; # 20강: 동기식 TCP 통신 예제
    esac

    # 각 강의별로 소스 파일과 헤더 파일 디렉토리 생성
    mkdir -p ./src/lecture_${i}_${lecture_name}   # 예: cpp101/src/lecture_01_comparison
    mkdir -p ./include/lecture_${i}_${lecture_name} # 예: cpp101/include/lecture_01_comparison
done

# 라이브러리, 빌드 파일, vscode 설정 파일 및 기타 디렉토리 생성
mkdir -p ./lib
mkdir -p ./.vscode
mkdir -p ./docs

# 기본 파일 생성
touch ./CMakeLists.txt
touch ./README.md

# VSCode 설정 파일 생성
touch ./.vscode/settings.json
touch ./.vscode/launch.json
touch ./.vscode/tasks.json

touch ./docs/lecture_notes.md

# 프로젝트 디렉토리 구조 확인 메시지 출력
echo "Project structure has been created successfully."
