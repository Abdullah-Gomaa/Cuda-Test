import tensorflow as tf

print("TensorFlow version:", tf.__version__)

# Check if GPU is available
gpus = tf.config.list_physical_devices('GPU')
if gpus:
    print("GPU is detected!")
    for gpu in gpus:
        print("GPU device:", gpu)
else:
    print("No GPU detected. TensorFlow is using CPU.")
