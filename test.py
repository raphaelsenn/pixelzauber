def convert_p5_to_p2(input_path, output_path):
    with open(input_path, 'rb') as f:
        # Read header
        assert f.readline().strip() == b'P5'
        dimensions = f.readline()
        while dimensions.startswith(b'#'):  # skip comments
            dimensions = f.readline()
        width, height = map(int, dimensions.strip().split())
        maxval = int(f.readline().strip())

        # Read binary data
        pixels = f.read()

    # Write ASCII (P2) PGM
    with open(output_path, 'w') as f:
        f.write('P2\n')
        f.write('# This is a comment!\n')
        f.write(f'{width}  {height}\n')
        f.write(f'{maxval}\n')

        for i in range(height):
            row = [str(pixels[i * width + j]) for j in range(width)]
            f.write('  '.join(row) + '\n ')

# Example usage
convert_p5_to_p2('motion05.512.pgm', 'pgm/motion05.pgm')
convert_p5_to_p2('motion06.512.pgm', 'pgm/motion06.pgm')