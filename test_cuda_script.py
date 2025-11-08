import torch


print("CUDA available:", torch.cuda.is_available())
print("Torch version:", torch.__version__)
print(torch.cuda.is_available()) 
print(torch.cuda.get_device_name(0))