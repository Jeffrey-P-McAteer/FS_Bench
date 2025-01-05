# FS_Bench

FS_Bench measures how closely your application-level filesystem performance is to hardware performance.

Many things can degrade the performance of an operating system, none so fatal as accidentially configuring a bad filesystem.

# Building

For Windows:

```bash
.\build.bat
```

For Linux + Mac

```bash
./build.sh
```


# Running

```bash

```

# Measured numbers from hardware configurations

Thinkpad P14s NVME drive running Arch Linux with the BTRFS filesystem

```
test_folder="/j/downloads/test-space"
folder_device_path=/dev/nvme0n1p3
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 0m 4s 542.5ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 0.04500ms (max 1.95900ms min 0.03300ms deviation of 1.92600ms) to complete write+delete+write data (107,500.00000 megabytes per second, 17,200 files tested)
 .dll files averaged 0.04500ms (max 1.83400ms min 0.03300ms deviation of 1.80100ms) to complete write+delete+write data (110,000.00000 megabytes per second, 17,600 files tested)
 .txt files averaged 0.04500ms (max 1.57500ms min 0.03300ms deviation of 1.54200ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
.json files averaged 0.04500ms (max 0.97000ms min 0.03300ms deviation of 0.93700ms) to complete write+delete+write data (95,000.00000 megabytes per second, 15,200 files tested)
  .so files averaged 0.04500ms (max 2.16700ms min 0.03300ms deviation of 2.13400ms) to complete write+delete+write data (110,625.00000 megabytes per second, 17,700 files tested)
 .bin files averaged 0.04500ms (max 1.38500ms min 0.03300ms deviation of 1.35200ms) to complete write+delete+write data (96,875.00000 megabytes per second, 15,500 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.04500ms (max 0.05100ms min 0.03700ms deviation of 0.01400ms) to complete write+delete+write data (107,500.00000 megabytes per second, 17,200 files tested)
 .dll files averaged 0.04500ms (max 0.05000ms min 0.03700ms deviation of 0.01300ms) to complete write+delete+write data (110,000.00000 megabytes per second, 17,600 files tested)
 .txt files averaged 0.04500ms (max 0.05000ms min 0.03700ms deviation of 0.01300ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
.json files averaged 0.04500ms (max 0.05000ms min 0.03700ms deviation of 0.01300ms) to complete write+delete+write data (95,000.00000 megabytes per second, 15,200 files tested)
  .so files averaged 0.04500ms (max 0.05000ms min 0.03700ms deviation of 0.01300ms) to complete write+delete+write data (110,625.00000 megabytes per second, 17,700 files tested)
 .bin files averaged 0.04500ms (max 0.05000ms min 0.03700ms deviation of 0.01300ms) to complete write+delete+write data (96,875.00000 megabytes per second, 15,500 files tested)
test_is_anomalous=false
```

