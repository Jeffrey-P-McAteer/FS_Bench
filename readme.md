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
folder_device_path=/dev/nvme1n1p3
Completed writing 6,250.0 GB of data to 100,000 files.
Test took 0m 4s 548.1ms
= = = = Absolute MIN/MAX Report (includes statistical outlier figures) = = = =
 .exe files averaged 0.04500ms (max 0.68300ms min 0.03500ms deviation of 0.64800ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
 .dll files averaged 0.04500ms (max 0.99400ms min 0.03500ms deviation of 0.95900ms) to complete write+delete+write data (115,625.00000 megabytes per second, 18,500 files tested)
 .txt files averaged 0.04500ms (max 0.42500ms min 0.03500ms deviation of 0.39000ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
.json files averaged 0.04500ms (max 0.41900ms min 0.03500ms deviation of 0.38400ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
  .so files averaged 0.04500ms (max 1.01700ms min 0.03500ms deviation of 0.98200ms) to complete write+delete+write data (107,500.00000 megabytes per second, 17,200 files tested)
 .bin files averaged 0.04500ms (max 1.40800ms min 0.03500ms deviation of 1.37300ms) to complete write+delete+write data (90,625.00000 megabytes per second, 14,500 files tested)
= = = = 10% normal distribution MIN/MAX Report (removes statistical outlier figures) = = = =
 .exe files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
 .dll files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (115,625.00000 megabytes per second, 18,500 files tested)
 .txt files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (103,125.00000 megabytes per second, 16,500 files tested)
.json files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (105,000.00000 megabytes per second, 16,800 files tested)
  .so files averaged 0.03400ms (max 0.05100ms min 0.03800ms deviation of 0.01300ms) to complete write+delete+write data (107,500.00000 megabytes per second, 17,200 files tested)
 .bin files averaged 0.03400ms (max 0.05000ms min 0.03800ms deviation of 0.01200ms) to complete write+delete+write data (90,625.00000 megabytes per second, 14,500 files tested)
test_is_anomalous=false
```

QEMU VM running Windows 11 from an NVME drive connected to a thunderbolt port with an NTFS filesystem

```

```


