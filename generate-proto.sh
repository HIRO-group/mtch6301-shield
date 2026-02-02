#!/usr/bin/env bash
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROTO_DIR=${PROJECT_DIR}/proto
OUT_DIR=${PROJECT_DIR}/include/generated

rm ${OUT_DIR}/*.h

protoc --plugin=protoc-gen-eams=${PROJECT_DIR}/EmbeddedProto/protoc-gen-eams -I ${PROTO_DIR} --eams_out=${OUT_DIR} ${PROTO_DIR}/*.proto