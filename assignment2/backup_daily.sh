#!/bin/bash

SOURCE_NAME="/home/sundarraj/Pictures/Screenshots"
DESTINATION_NAME="/home/sundarraj/Documents"
BACKUP_NAME="backup_$(date +%Y-%m-%d_%H-%M-%S).tar.gz"
tar -czf "${DESTINATION_NAME}/${BACKUP_NAME}" "${SOURCE_NAME}"

