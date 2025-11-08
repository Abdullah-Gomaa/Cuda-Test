# CUDA, NVIDIA Driver, and PyTorch GPU Installation Guide (Ubuntu/Linux)

This guide explains how to set up CUDA, configure NVIDIA drivers, and install GPU-enabled PyTorch step by step on any Ubuntu-based system.

## 1. Check System Information

Before starting, verify your environment:

```bash
# OS and version
lsb_release -a
# or
cat /etc/os-release

# Kernel version
uname -r

# GPU info
lspci | grep -E "VGA|3D"

# Check if NVIDIA driver is installed
nvidia-smi
```


## 2. Install NVIDIA Drivers (if not already installed)

Use Ubuntu’s official repository for a clean installation:

```bash
sudo apt update
sudo ubuntu-drivers devices
sudo ubuntu-drivers install
sudo reboot

```

.

After reboot, verify:

```bash

nvidia-smi
```



## 3. Install CUDA Toolkit (Recommended via Ubuntu Repo)

Using the Ubuntu repository keeps dependencies clean and automatically compatible:

```bash
sudo apt update
sudo apt install nvidia-cuda-toolkit
```



## 4. Add CUDA to PATH (if not automatically configured)

Edit your `~/.bashrc`:

```bash
echo 'export PATH=/usr/local/cuda/bin:$PATH' >> ~/.bashrc
echo 'export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH' >> ~/.bashrc
source ~/.bashrc
```

Verify:

nvcc --version

You should see CUDA version info.


## 5. (Hybrid GPU Users) — Set Up prime-run

For laptops with Intel + NVIDIA hybrid graphics:

```bash
sudo apt install nvidia-prime
```

If `prime-run` is missing, create it manually:

```bash
sudo nano /usr/local/bin/prime-run
```

Paste the following content:

```bash
#!/bin/bash
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia __VK_LAYER_NV_optimus=NVIDIA_only "$@"

```

Make it executable:

```bash
sudo chmod +x /usr/local/bin/prime-run

```

Test it:

```bash
prime-run nvidia-smi

```

To check or change GPU mode:

```bash
sudo prime-select query       # Shows current mode
sudo prime-select nvidia      # Always use NVIDIA
sudo prime-select intel       # Use Intel only
sudo prime-select on-demand   # Default: use Intel, offload to NVIDIA when needed

```

## 6. Verify CUDA Installation

```bash
nvcc --version
nvidia-smi

```


If both show valid info (driver + compiler), your CUDA environment is ready.

## 7. Install PyTorch with GPU (CUDA) Support


### Step 1: Remove any CPU-only version

```bash
pip uninstall torch torchvision torchaudio -y
```

### Step 2: Install CUDA-enabled PyTorch

For CUDA 12.4 build:

```bash
pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu124

```

## 8. Verify GPU Access in PyTorch

```bash
python3 -c "import torch; print(torch.cuda.is_available()); print(torch.cuda.get_device_name(0))"
```

Expected output:

```yaml
True
NVIDIA GeForce RTX 2050

```

For hybrid systems, use:

```bash
prime-run python3 test_cuda_script.py
```
