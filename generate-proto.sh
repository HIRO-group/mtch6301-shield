#!/usr/bin/env bash
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROTO_DIR=${PROJECT_DIR}/proto
CPP_OUT_DIR=${PROJECT_DIR}/include/generated
PY_OUT_DIR=${PROJECT_DIR}/tools/monitor/generated

rm -f ${CPP_OUT_DIR}/*.h
rm -f ${PY_OUT_DIR}/*.py

protoc \
  --plugin=protoc-gen-eams=${PROJECT_DIR}/lib/EmbeddedProto/protoc-gen-eams \
  -I ${PROTO_DIR} \
  --eams_out=${CPP_OUT_DIR} \
  --python_out=${PY_OUT_DIR} \
  ${PROTO_DIR}/*.proto

touch ${PY_OUT_DIR}/__init__.py