#!/bin/bash

# Define variables
SOURCE_DIR="/home/sundarraj/Downloads/"
BACKUP_DIR="/home/sundarraj/Documents/backups/"
DATE="$(date +%Y-%m-%d_%H-%M-%S)"

# Create daily backup
tar -czf $BACKUP_DIR/daily/backup_$DATE.tar.gz $SOURCE_DIR

# Create weekly backup on Sundays
if [ $(date +%u) -eq 7 ]; then
    tar -czf $BACKUP_DIR/weekly/backup_$DATE.tar.gz $SOURCE_DIR
fi

# Create monthly backup on the first day of the month
if [ $(date +%d) -eq 01 ]; then
    tar -czf $BACKUP_DIR/monthly/backup_$DATE.tar.gz $SOURCE_DIR
fi
