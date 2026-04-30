#!/bin/bash

LAYOUT_ID="AW4Ro"
KEYBOARD="voyager"

folder="${KEYBOARD}_${LAYOUT_ID}"
filename="zsa_${KEYBOARD}_${LAYOUT_ID}.bin"

command -v gh >/dev/null 2>&1 || {
  echo "GitHub CLI is required but not installed. Aborting."
  exit 1
}

command -v zapp >/dev/null 2>&1 || {
  echo "zapp is required but not installed. Aborting."
  exit 1
}

echo "Checking if build artifact already exists"

if [ -d $folder ]; then
  if [ -f "${folder}/${filename}" ]; then
    echo "Build artifact exists, cleaning up"
    rm "${folder}/${filename}"
  fi
  rmdir "$folder"
fi

echo "{\"layout_id\":\"$LAYOUT_ID\", \"layout_geometry\":\"$KEYBOARD\"}" | gh workflow run fetch-and-build-layout.yml --json

runlist=$(gh run list)

run_id=$(echo "$runlist" | awk -F'\t' 'NR==1 {print $7}')

gh run watch "$run_id"

gh run view "$run_id"

if [ $? -eq 0 ]; then
  echo "GitHub Actions completed successfully"
  gh run download "$run_id"

  ls -ltrh "$folder"
  read -p "Flashing with $filename. Do you wish to continue? (Y/n) " -n 1 -r
  echo
  echo

  if [[ $REPLY =~ ^[Yy]$ ]]; then
    cd $folder || exit
    zapp flash $filename
  else
    echo "Aborting."
  fi
else
  echo "GitHub Actions did not complete successfully, aborting."
fi
